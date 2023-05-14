// Generated by gencpp from file unity_robotics_demo_msgs/ObjectPoseServiceResponse.msg
// DO NOT EDIT!


#ifndef UNITY_ROBOTICS_DEMO_MSGS_MESSAGE_OBJECTPOSESERVICERESPONSE_H
#define UNITY_ROBOTICS_DEMO_MSGS_MESSAGE_OBJECTPOSESERVICERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Pose.h>

namespace unity_robotics_demo_msgs
{
template <class ContainerAllocator>
struct ObjectPoseServiceResponse_
{
  typedef ObjectPoseServiceResponse_<ContainerAllocator> Type;

  ObjectPoseServiceResponse_()
    : object_pose()  {
    }
  ObjectPoseServiceResponse_(const ContainerAllocator& _alloc)
    : object_pose(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _object_pose_type;
  _object_pose_type object_pose;





  typedef boost::shared_ptr< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ObjectPoseServiceResponse_

typedef ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<std::allocator<void> > ObjectPoseServiceResponse;

typedef boost::shared_ptr< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse > ObjectPoseServiceResponsePtr;
typedef boost::shared_ptr< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse const> ObjectPoseServiceResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace unity_robotics_demo_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'unity_robotics_demo_msgs': ['/home/poskuka-nearlab/catkin_ws/src/ros_packages/unity_robotics_demo_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4f370b349a20e2e0029b6c926ba1b874";
  }

  static const char* value(const ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4f370b349a20e2e0ULL;
  static const uint64_t static_value2 = 0x029b6c926ba1b874ULL;
};

template<class ContainerAllocator>
struct DataType< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "unity_robotics_demo_msgs/ObjectPoseServiceResponse";
  }

  static const char* value(const ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Pose object_pose\n\
\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.object_pose);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ObjectPoseServiceResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::unity_robotics_demo_msgs::ObjectPoseServiceResponse_<ContainerAllocator>& v)
  {
    s << indent << "object_pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.object_pose);
  }
};

} // namespace message_operations
} // namespace ros

#endif // UNITY_ROBOTICS_DEMO_MSGS_MESSAGE_OBJECTPOSESERVICERESPONSE_H
