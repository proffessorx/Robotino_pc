// Generated by gencpp from file robotino_msgs/SetGripperStateRequest.msg
// DO NOT EDIT!


#ifndef ROBOTINO_MSGS_MESSAGE_SETGRIPPERSTATEREQUEST_H
#define ROBOTINO_MSGS_MESSAGE_SETGRIPPERSTATEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace robotino_msgs
{
template <class ContainerAllocator>
struct SetGripperStateRequest_
{
  typedef SetGripperStateRequest_<ContainerAllocator> Type;

  SetGripperStateRequest_()
    : state(false)  {
    }
  SetGripperStateRequest_(const ContainerAllocator& _alloc)
    : state(false)  {
  (void)_alloc;
    }



   typedef uint8_t _state_type;
  _state_type state;





  typedef boost::shared_ptr< ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetGripperStateRequest_

typedef ::robotino_msgs::SetGripperStateRequest_<std::allocator<void> > SetGripperStateRequest;

typedef boost::shared_ptr< ::robotino_msgs::SetGripperStateRequest > SetGripperStateRequestPtr;
typedef boost::shared_ptr< ::robotino_msgs::SetGripperStateRequest const> SetGripperStateRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace robotino_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'robotino_msgs': ['/home/robotino/catkin_ws/src/robotino/robotino-ros-pkg/robotino_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "001fde3cab9e313a150416ff09c08ee4";
  }

  static const char* value(const ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x001fde3cab9e313aULL;
  static const uint64_t static_value2 = 0x150416ff09c08ee4ULL;
};

template<class ContainerAllocator>
struct DataType< ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robotino_msgs/SetGripperStateRequest";
  }

  static const char* value(const ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool state\n\
";
  }

  static const char* value(const ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetGripperStateRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robotino_msgs::SetGripperStateRequest_<ContainerAllocator>& v)
  {
    s << indent << "state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.state);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOTINO_MSGS_MESSAGE_SETGRIPPERSTATEREQUEST_H
