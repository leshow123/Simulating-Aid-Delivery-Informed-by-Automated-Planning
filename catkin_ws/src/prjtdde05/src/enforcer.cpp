#include <ros/ros.h>
#include <std_srvs/Empty.h>
#include <std_msgs/Empty.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>
#include "rosplan_action_interface/RPActionInterface.h"
#include <move_base_msgs/MoveBaseAction.h>
#include "mongodb_store/message_store.h"
#include <actionlib/client/simple_action_client.h>
#include "rosplan_dispatch_msgs/ActionDispatch.h"
#include "rosplan_dispatch_msgs/ActionFeedback.h"
#include "rosplan_knowledge_msgs/KnowledgeUpdateService.h"
#include "rosplan_knowledge_msgs/KnowledgeItem.h"
#include <vector>
#include <boost/foreach.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/function.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <tf/LinearMath/Quaternion.h>
#include <tf/LinearMath/Vector3.h>

namespace KCL_rosplan
{

class Quadrotor : public RPActionInterface
{
private:
  ros::NodeHandle node_handle_;

  ros::WallTime start;

  // knowledge interface
  ros::ServiceClient update_knowledge_client;

  // costmap interface
  ros::ServiceClient clear_costmaps_client;

  // topic for publishing action feedback
  ros::Publisher feedback_publisher_;

  ros::Publisher text_publisher_;
  std_msgs::String text_;
  
  // define action client to receive messages from move_base
  actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> action_client;

  // database - waypoints are retrieved from here
  mongodb_store::MessageStoreProxy message_store;

  // to parse-in odom to vector store 
  nav_msgs::Odometry current_entry;

  // Keep the odometry history
  std::vector<nav_msgs::Odometry> odom_history;
  //std::vector< boost::shared_ptr<nav_msgs::Odometry> > odom_history;
  
  float action_duration;
  bool action_status;
  bool goal_act_init;
  double cumm_distance;


  // helper function for feedback publishing
  void publishFeedback(int action_id, std::string fbstat)
  {
    rosplan_dispatch_msgs::ActionFeedback fb;
    fb.action_id = action_id;
    fb.status = fbstat;
    feedback_publisher_.publish(fb);
  } 


public:

  Quadrotor(ros::NodeHandle &nh, std::string &actionserver) : node_handle_(nh), message_store(nh), action_client(actionserver, true)
  { 

    // initialize costmaps client - this service is used to clear costmaps 
    clear_costmaps_client = nh.serviceClient<std_srvs::Empty>("/move_base/clear_costmaps");

    // feedback to the planning system will be send through this topic
    feedback_publisher_ = node_handle_.advertise<rosplan_dispatch_msgs::ActionFeedback>("/kcl_rosplan/action_feedback", 10, true);

    // ...just a printer
    text_publisher_ = node_handle_.advertise<std_msgs::String>("/printer", 10);
    
    // ...just a crude timer
    start = ros::WallTime::now();
 
    cumm_distance = 0.0;
    action_duration = 0.0;
    action_status = false;
    goal_act_init = false;

  }


  double getDistance(){return cumm_distance;}

  void odometryCallback(const nav_msgs::Odometry::ConstPtr& _odometry)
  {

   if(goal_act_init==true)
    {
           odom_history.push_back(*_odometry);
           ros::WallDuration tss = ros::WallTime::now()-start;  //tss = time since start (of moveGoal action)
           double tss_ = tss.toNSec() * 1e-6;
          
	   if(tss_ >= 5000)  // approx 5 seconds 
	     {        
		nav_msgs::Odometry first_entry = odom_history.front();  
	       current_entry = *_odometry;
	       double x = current_entry.pose.pose.position.x - first_entry.pose.pose.position.x;
	       double y = current_entry.pose.pose.position.y - first_entry.pose.pose.position.y;
	       double distance =  std::pow((double)x*x+y*y, 0.50);
	       odom_history.clear();

               //reset start
	       start = ros::WallTime::now();
	       // this odometry now becomes first-element
	       odom_history.push_back(current_entry); 
	       cumm_distance += distance;
	   
	     }

    }
  
  }


  // --- ACTION DISPATCH --
  bool concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg)
  {

    text_ = std_msgs::String();
    
    // parse action message
    std::string actionName = msg->name;
    int action_id = msg->action_id;
    action_duration = msg->duration;
    std::vector<diagnostic_msgs::KeyValue> parameters_vector = msg->parameters;   // list if key-value pairs

    if (actionName.compare("flywithcarrier") == 0)
	{
		action_status = flywithcarrier(action_id, parameters_vector);
		return action_status;
	}
  }

  
  bool flywithcarrier(const int action_id, const std::vector<diagnostic_msgs::KeyValue> &parameters_vector)
  {
        publishFeedback(action_id,"Action enabled");
        geometry_msgs::PoseStamped p;
	
	// flight
	std::string wpID = parameters_vector[3].value;   // so wpID could be 'depot' or 'location'
	text_.data = wpID;
	text_publisher_.publish(text_);
	
	if(wpID.empty())
	{
		ROS_INFO("Quadrotor:: Aborting action; No destination");
		return false;
	}
	
	// flight :: get victim location [x,y,[z]] by query
	std::vector< boost::shared_ptr<geometry_msgs::PoseStamped> > location_from_db; // all locations in-fact
	
	if(message_store.queryNamed<geometry_msgs::PoseStamped>(wpID, location_from_db)) 
	{
		if(location_from_db.size()<1) 
		{
			ROS_INFO("FLY-WITH-CARRIER:: Aborting; no destination: %s", wpID.c_str());
			return false; 
		}

		if(location_from_db.size()>1)
		{
			ROS_INFO("FLY-WITH-CARRIER:: Error: multiple destinations share the same coordinate");
			return false;     
		}
		
		ROS_INFO("Quadrotor::Action FLY-WITH-CARRIER dispatched.");

		text_.data = "====== DESTINATION COORDS ======";
		text_publisher_.publish(text_);
		                  
		BOOST_FOREACH(boost::shared_ptr<geometry_msgs::PoseStamped> p, location_from_db)
                   {
			text_.data = std::to_string(p->pose.position.x) + " , " + std::to_string(p->pose.position.y); 
			text_publisher_.publish(text_);
		   }
		
		ROS_INFO("Quadrotor:: Sending goal...");
		start = ros::WallTime::now();
		/*
		Bcos start is later accessed and changed by odomCallBack, 
		and so will affect time-taken calc if 'updated' start used
		*/
		ros::WallTime copy_of_start = start;
		bool goalReached = moveToGoal(action_id, location_from_db);
		goal_act_init = false; //unset goal_act_init
		ros::WallTime end = ros::WallTime::now();
		double total_time = (end-copy_of_start).toNSec() * 1e-6;
		text_.data = "Total time taken: " + std::to_string(total_time);  // in millisecs
		text_publisher_.publish(text_);	

		// publish total distance travelled estimate
		text_.data = "Approx. distance per leg (Euclidean): " + std::to_string(cumm_distance); 
		cumm_distance = 0.0; 
		text_publisher_.publish(text_);	
		
		return true;
		
	}
	else
	{
		publishFeedback(action_id,"Quadrotor FLY-WITH-CARRIER:: Aborting action; query to scene database failed");
		return 0;
	}
	
  }


  bool moveToGoal(int action_id, const std::vector< boost::shared_ptr<geometry_msgs::PoseStamped> > &vlfd)
  {

	//some overhead; wait for ActionServer toconnect to this client
	ROS_INFO("Quadrotor:: Starting move_base action server... ");
	action_client.waitForServer();

	move_base_msgs::MoveBaseGoal goal;

	//set up the frame parameters
	goal.target_pose.header.frame_id = "map";
	goal.target_pose.header.stamp = ros::Time::now();   
	  
	//  - get shit done -
	goal.target_pose.pose.position.x =  vlfd[0]->pose.position.x;
	goal.target_pose.pose.position.y =  vlfd[0]->pose.position.y;
	goal.target_pose.pose.position.z =  vlfd[0]->pose.position.z;
	goal.target_pose.pose.orientation.x = 0.0;
	goal.target_pose.pose.orientation.y = 0.0;
	goal.target_pose.pose.orientation.z = 0.0;
	goal.target_pose.pose.orientation.w = 1.0;
	
        // set goal_act_init and send goal
        goal_act_init = true;
	action_client.sendGoal(goal);               

	bool finished_on_time = action_client.waitForResult();

	if(finished_on_time)
	{
	   if(action_client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
		  ROS_INFO("Quadrotor::Destination reached");
                  //unset goal_act_init
                  goal_act_init = false;
		  return true;
	   }
	   else
	   {
		  std_srvs::Empty emptySrv;
		  clear_costmaps_client.call(emptySrv);
		  goal_act_init = false;
		  return false;
	   }
	}
	else {publishFeedback(action_id,"Action timed-out"); action_client.cancelAllGoals(); goal_act_init = false; return false;}
  }
 

};

} // namespace end


int main(int argc, char **argv)
{
  ros::init(argc, argv, "enforcer");
  ros::NodeHandle nh("~");                 

  // initialize actionserver name by request to ROS parameter server
  std::string actionserver;
  nh.param("action_server", actionserver, std::string("/move_base"));

  KCL_rosplan::Quadrotor action_listening_station(nh, actionserver);

  ros::Subscriber odometry_sub = nh.subscribe("/odom", 10, &KCL_rosplan::Quadrotor::odometryCallback, &action_listening_station);
  ros::Subscriber odometry_sub2 = nh.subscribe("/odom", 10, &KCL_rosplan::Quadrotor::odometryCallback, &action_listening_station);
  
  // Multithreaded spinner
  ros::AsyncSpinner spinner(2); 
  ros::Rate r(10);
  spinner.start();
  
  action_listening_station.runActionInterface();

  return 0;
}
