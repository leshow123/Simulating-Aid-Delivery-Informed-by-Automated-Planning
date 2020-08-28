# Simulating-Aid-Delivery-Informed-by-Automated-Planning
Abstract: A simulation implementation of an automated decision planning system for a robot in a disaster recovery context, by interfacing the navigation module. Goal tasks are defined by a planning problem and dispatched using ROSPlan.

Why is the project useful?

The project motivates the Automated Planning in Robtics by extending the ROSPlan framework. Importantly, it shows how this can be achieved in a simulated environment prior
to deployment on a robot platform. A test-bed for both experimenced ROS users and beginners alike.

The scenario simulated is that of aid deliveries to different waypoints where disaster victims have been identified. It could easily fit a grocery delivery use-case or
similar use-cases, provided the right sensor add-ons in Gazebo are installed. A Turtlebot3 is the robot of choice. 

Running the project

The folder 'prjtdde05' contains the important 'starter' files for running the project. Importantly, a waypoint file containing victim locations, a C++ program to extend the
ROSPlan framework and connect the simulation environment, as well as PDDL planning domain files. YAML files also help setup some key configuration, along with a (g)SLAM map file of the environment. Refer ROS documentation on compiling the catkin workspace! A detailed understanding of linking C++ modules is also important.

Note that the version of ROS implemented is Kinetic. Hence, the project is not guaranteed for higher versions (or even older ones).

Where to get help?

Not minding that a catkin_ws folder already exist, strong advise is to start here: http://wiki.ros.org/catkin/Tutorials/create_a_workspace if you are a beginner in ROS. However, the assumption is that you have basic skills in C++ programming.