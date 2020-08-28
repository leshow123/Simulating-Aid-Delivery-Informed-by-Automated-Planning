// Generated by gencpp from file rosplan_knowledge_msgs/SetIntRequest.msg
// DO NOT EDIT!


#ifndef ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_SETINTREQUEST_H
#define ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_SETINTREQUEST_H


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
struct SetIntRequest_
{
  typedef SetIntRequest_<ContainerAllocator> Type;

  SetIntRequest_()
    : value(0)  {
    }
  SetIntRequest_(const ContainerAllocator& _alloc)
    : value(0)  {
  (void)_alloc;
    }



   typedef int32_t _value_type;
  _value_type value;





  typedef boost::shared_ptr< ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetIntRequest_

typedef ::rosplan_knowledge_msgs::SetIntRequest_<std::allocator<void> > SetIntRequest;

typedef boost::shared_ptr< ::rosplan_knowledge_msgs::SetIntRequest > SetIntRequestPtr;
typedef boost::shared_ptr< ::rosplan_knowledge_msgs::SetIntRequest const> SetIntRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b3087778e93fcd34cc8d65bc54e850d1";
  }

  static const char* value(const ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb3087778e93fcd34ULL;
  static const uint64_t static_value2 = 0xcc8d65bc54e850d1ULL;
};

template<class ContainerAllocator>
struct DataType< ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rosplan_knowledge_msgs/SetIntRequest";
  }

  static const char* value(const ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 value\n\
";
  }

  static const char* value(const ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.value);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetIntRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rosplan_knowledge_msgs::SetIntRequest_<ContainerAllocator>& v)
  {
    s << indent << "value: ";
    Printer<int32_t>::stream(s, indent + "  ", v.value);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_SETINTREQUEST_H
