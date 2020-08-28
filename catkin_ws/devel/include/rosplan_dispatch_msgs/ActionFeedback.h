// Generated by gencpp from file rosplan_dispatch_msgs/ActionFeedback.msg
// DO NOT EDIT!


#ifndef ROSPLAN_DISPATCH_MSGS_MESSAGE_ACTIONFEEDBACK_H
#define ROSPLAN_DISPATCH_MSGS_MESSAGE_ACTIONFEEDBACK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <diagnostic_msgs/KeyValue.h>

namespace rosplan_dispatch_msgs
{
template <class ContainerAllocator>
struct ActionFeedback_
{
  typedef ActionFeedback_<ContainerAllocator> Type;

  ActionFeedback_()
    : action_id(0)
    , status()
    , information()  {
    }
  ActionFeedback_(const ContainerAllocator& _alloc)
    : action_id(0)
    , status(_alloc)
    , information(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _action_id_type;
  _action_id_type action_id;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _status_type;
  _status_type status;

   typedef std::vector< ::diagnostic_msgs::KeyValue_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::diagnostic_msgs::KeyValue_<ContainerAllocator> >::other >  _information_type;
  _information_type information;





  typedef boost::shared_ptr< ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct ActionFeedback_

typedef ::rosplan_dispatch_msgs::ActionFeedback_<std::allocator<void> > ActionFeedback;

typedef boost::shared_ptr< ::rosplan_dispatch_msgs::ActionFeedback > ActionFeedbackPtr;
typedef boost::shared_ptr< ::rosplan_dispatch_msgs::ActionFeedback const> ActionFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rosplan_dispatch_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'rosplan_dispatch_msgs': ['/home/olumide/TDDE05/catkin_ws/src/rosplan/rosplan_dispatch_msgs/msg', '/home/olumide/TDDE05/catkin_ws/devel/share/rosplan_dispatch_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'diagnostic_msgs': ['/opt/ros/kinetic/share/diagnostic_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e28991799802dd700e1390bf56614b89";
  }

  static const char* value(const ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe28991799802dd70ULL;
  static const uint64_t static_value2 = 0x0e1390bf56614b89ULL;
};

template<class ContainerAllocator>
struct DataType< ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rosplan_dispatch_msgs/ActionFeedback";
  }

  static const char* value(const ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#actionFeedback message\n\
int32 action_id\n\
string status\n\
diagnostic_msgs/KeyValue[] information\n\
\n\
================================================================================\n\
MSG: diagnostic_msgs/KeyValue\n\
string key # what to label this value when viewing\n\
string value # a value to track over time\n\
";
  }

  static const char* value(const ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.action_id);
      stream.next(m.status);
      stream.next(m.information);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ActionFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rosplan_dispatch_msgs::ActionFeedback_<ContainerAllocator>& v)
  {
    s << indent << "action_id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.action_id);
    s << indent << "status: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.status);
    s << indent << "information[]" << std::endl;
    for (size_t i = 0; i < v.information.size(); ++i)
    {
      s << indent << "  information[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::diagnostic_msgs::KeyValue_<ContainerAllocator> >::stream(s, indent + "    ", v.information[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSPLAN_DISPATCH_MSGS_MESSAGE_ACTIONFEEDBACK_H
