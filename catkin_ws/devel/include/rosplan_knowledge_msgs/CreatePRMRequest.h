// Generated by gencpp from file rosplan_knowledge_msgs/CreatePRMRequest.msg
// DO NOT EDIT!


#ifndef ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_CREATEPRMREQUEST_H
#define ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_CREATEPRMREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rosplan_knowledge_msgs
{
template <class ContainerAllocator>
struct CreatePRMRequest_
{
  typedef CreatePRMRequest_<ContainerAllocator> Type;

  CreatePRMRequest_()
    : nr_waypoints(0)
    , min_distance(0.0)
    , casting_distance(0.0)
    , connecting_distance(0.0)
    , occupancy_threshold(0)
    , total_attempts(0)  {
    }
  CreatePRMRequest_(const ContainerAllocator& _alloc)
    : nr_waypoints(0)
    , min_distance(0.0)
    , casting_distance(0.0)
    , connecting_distance(0.0)
    , occupancy_threshold(0)
    , total_attempts(0)  {
  (void)_alloc;
    }



   typedef int32_t _nr_waypoints_type;
  _nr_waypoints_type nr_waypoints;

   typedef float _min_distance_type;
  _min_distance_type min_distance;

   typedef float _casting_distance_type;
  _casting_distance_type casting_distance;

   typedef float _connecting_distance_type;
  _connecting_distance_type connecting_distance;

   typedef int8_t _occupancy_threshold_type;
  _occupancy_threshold_type occupancy_threshold;

   typedef int32_t _total_attempts_type;
  _total_attempts_type total_attempts;





  typedef boost::shared_ptr< ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> const> ConstPtr;

}; // struct CreatePRMRequest_

typedef ::rosplan_knowledge_msgs::CreatePRMRequest_<std::allocator<void> > CreatePRMRequest;

typedef boost::shared_ptr< ::rosplan_knowledge_msgs::CreatePRMRequest > CreatePRMRequestPtr;
typedef boost::shared_ptr< ::rosplan_knowledge_msgs::CreatePRMRequest const> CreatePRMRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rosplan_knowledge_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'diagnostic_msgs': ['/opt/ros/kinetic/share/diagnostic_msgs/cmake/../msg'], 'rosplan_knowledge_msgs': ['/home/olumide/TDDE05/catkin_ws/src/rosplan/rosplan_knowledge_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5f7c217e90f8fff8f615b66b6e7c4601";
  }

  static const char* value(const ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5f7c217e90f8fff8ULL;
  static const uint64_t static_value2 = 0xf615b66b6e7c4601ULL;
};

template<class ContainerAllocator>
struct DataType< ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rosplan_knowledge_msgs/CreatePRMRequest";
  }

  static const char* value(const ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 nr_waypoints\n\
float32 min_distance\n\
float32 casting_distance\n\
float32 connecting_distance\n\
int8 occupancy_threshold\n\
int32 total_attempts\n\
";
  }

  static const char* value(const ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.nr_waypoints);
      stream.next(m.min_distance);
      stream.next(m.casting_distance);
      stream.next(m.connecting_distance);
      stream.next(m.occupancy_threshold);
      stream.next(m.total_attempts);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CreatePRMRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rosplan_knowledge_msgs::CreatePRMRequest_<ContainerAllocator>& v)
  {
    s << indent << "nr_waypoints: ";
    Printer<int32_t>::stream(s, indent + "  ", v.nr_waypoints);
    s << indent << "min_distance: ";
    Printer<float>::stream(s, indent + "  ", v.min_distance);
    s << indent << "casting_distance: ";
    Printer<float>::stream(s, indent + "  ", v.casting_distance);
    s << indent << "connecting_distance: ";
    Printer<float>::stream(s, indent + "  ", v.connecting_distance);
    s << indent << "occupancy_threshold: ";
    Printer<int8_t>::stream(s, indent + "  ", v.occupancy_threshold);
    s << indent << "total_attempts: ";
    Printer<int32_t>::stream(s, indent + "  ", v.total_attempts);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_CREATEPRMREQUEST_H
