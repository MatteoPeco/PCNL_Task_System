// Generated by gencpp from file lwr_controllers/CartesianImpedancePoint.msg
// DO NOT EDIT!


#ifndef LWR_CONTROLLERS_MESSAGE_CARTESIANIMPEDANCEPOINT_H
#define LWR_CONTROLLERS_MESSAGE_CARTESIANIMPEDANCEPOINT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Pose.h>
#include <lwr_controllers/Stiffness.h>
#include <lwr_controllers/Stiffness.h>
#include <geometry_msgs/Wrench.h>

namespace lwr_controllers
{
template <class ContainerAllocator>
struct CartesianImpedancePoint_
{
  typedef CartesianImpedancePoint_<ContainerAllocator> Type;

  CartesianImpedancePoint_()
    : header()
    , x_FRI()
    , k_FRI()
    , d_FRI()
    , f_FRI()  {
    }
  CartesianImpedancePoint_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , x_FRI(_alloc)
    , k_FRI(_alloc)
    , d_FRI(_alloc)
    , f_FRI(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _x_FRI_type;
  _x_FRI_type x_FRI;

   typedef  ::lwr_controllers::Stiffness_<ContainerAllocator>  _k_FRI_type;
  _k_FRI_type k_FRI;

   typedef  ::lwr_controllers::Stiffness_<ContainerAllocator>  _d_FRI_type;
  _d_FRI_type d_FRI;

   typedef  ::geometry_msgs::Wrench_<ContainerAllocator>  _f_FRI_type;
  _f_FRI_type f_FRI;





  typedef boost::shared_ptr< ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> const> ConstPtr;

}; // struct CartesianImpedancePoint_

typedef ::lwr_controllers::CartesianImpedancePoint_<std::allocator<void> > CartesianImpedancePoint;

typedef boost::shared_ptr< ::lwr_controllers::CartesianImpedancePoint > CartesianImpedancePointPtr;
typedef boost::shared_ptr< ::lwr_controllers::CartesianImpedancePoint const> CartesianImpedancePointConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace lwr_controllers

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'geometry_msgs': ['/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg', '/usr/local/MATLAB/R2021a/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg'], 'lwr_controllers': ['/home/nearlab/catkin_ws/src/kuka-lwr/matlab_msg_gen_ros1/glnxa64/src/lwr_controllers/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "71b8c728a99ddb73ba603776d4733a5f";
  }

  static const char* value(const ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x71b8c728a99ddb73ULL;
  static const uint64_t static_value2 = 0xba603776d4733a5fULL;
};

template<class ContainerAllocator>
struct DataType< ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "lwr_controllers/CartesianImpedancePoint";
  }

  static const char* value(const ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n"
"# 1. If frame_id in header is NOT EMPTY, then x_FRI is considered to be the pose w.r.t. that frame, so the increment w.r.t. the current tip pose will be computed internally (in the teach pendant is equivalent to select the Cartesian increments to be in the WORLD frame) \n"
"# 2. If frame_id in header is EMPTY, then x_FRI is considered to be the pose w.r.t. to the current tip pose (in the teach pendant is equivalent to select the Cartesian increments to be in the TOOL frame)\n"
"# The increment (or offset) is x_FRI\n"
"geometry_msgs/Pose x_FRI\n"
"# The stiffness, damping and wrench are expressed in the current tip frame readed in the HWiface\n"
"lwr_controllers/Stiffness k_FRI\n"
"lwr_controllers/Stiffness d_FRI\n"
"geometry_msgs/Wrench f_FRI\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
"\n"
"================================================================================\n"
"MSG: lwr_controllers/Stiffness\n"
"# This represents a diagonal Cartesian stiffness\n"
"# It is motivated by the KDL class: http://people.mech.kuleuven.be/~rsmits/kdl/api/html/classKDL_1_1Stiffness.html\n"
"# The conversion would be straight-forward, however, a generic 6D stiffness matrix would be desirable\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 rx\n"
"float64 ry\n"
"float64 rz\n"
"================================================================================\n"
"MSG: geometry_msgs/Wrench\n"
"# This represents force in free space, separated into\n"
"# its linear and angular parts.\n"
"Vector3  force\n"
"Vector3  torque\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.x_FRI);
      stream.next(m.k_FRI);
      stream.next(m.d_FRI);
      stream.next(m.f_FRI);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CartesianImpedancePoint_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::lwr_controllers::CartesianImpedancePoint_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "x_FRI: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.x_FRI);
    s << indent << "k_FRI: ";
    s << std::endl;
    Printer< ::lwr_controllers::Stiffness_<ContainerAllocator> >::stream(s, indent + "  ", v.k_FRI);
    s << indent << "d_FRI: ";
    s << std::endl;
    Printer< ::lwr_controllers::Stiffness_<ContainerAllocator> >::stream(s, indent + "  ", v.d_FRI);
    s << indent << "f_FRI: ";
    s << std::endl;
    Printer< ::geometry_msgs::Wrench_<ContainerAllocator> >::stream(s, indent + "  ", v.f_FRI);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LWR_CONTROLLERS_MESSAGE_CARTESIANIMPEDANCEPOINT_H
