// Generated by gencpp from file unity_robotics_demo_msgs/ObjectPoseService.msg
// DO NOT EDIT!


#ifndef UNITY_ROBOTICS_DEMO_MSGS_MESSAGE_OBJECTPOSESERVICE_H
#define UNITY_ROBOTICS_DEMO_MSGS_MESSAGE_OBJECTPOSESERVICE_H

#include <ros/service_traits.h>


#include <unity_robotics_demo_msgs/ObjectPoseServiceRequest.h>
#include <unity_robotics_demo_msgs/ObjectPoseServiceResponse.h>


namespace unity_robotics_demo_msgs
{

struct ObjectPoseService
{

typedef ObjectPoseServiceRequest Request;
typedef ObjectPoseServiceResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ObjectPoseService
} // namespace unity_robotics_demo_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::unity_robotics_demo_msgs::ObjectPoseService > {
  static const char* value()
  {
    return "31d8db4c34c65d79af3330e45c30d801";
  }

  static const char* value(const ::unity_robotics_demo_msgs::ObjectPoseService&) { return value(); }
};

template<>
struct DataType< ::unity_robotics_demo_msgs::ObjectPoseService > {
  static const char* value()
  {
    return "unity_robotics_demo_msgs/ObjectPoseService";
  }

  static const char* value(const ::unity_robotics_demo_msgs::ObjectPoseService&) { return value(); }
};


// service_traits::MD5Sum< ::unity_robotics_demo_msgs::ObjectPoseServiceRequest> should match 
// service_traits::MD5Sum< ::unity_robotics_demo_msgs::ObjectPoseService > 
template<>
struct MD5Sum< ::unity_robotics_demo_msgs::ObjectPoseServiceRequest>
{
  static const char* value()
  {
    return MD5Sum< ::unity_robotics_demo_msgs::ObjectPoseService >::value();
  }
  static const char* value(const ::unity_robotics_demo_msgs::ObjectPoseServiceRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::unity_robotics_demo_msgs::ObjectPoseServiceRequest> should match 
// service_traits::DataType< ::unity_robotics_demo_msgs::ObjectPoseService > 
template<>
struct DataType< ::unity_robotics_demo_msgs::ObjectPoseServiceRequest>
{
  static const char* value()
  {
    return DataType< ::unity_robotics_demo_msgs::ObjectPoseService >::value();
  }
  static const char* value(const ::unity_robotics_demo_msgs::ObjectPoseServiceRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse> should match 
// service_traits::MD5Sum< ::unity_robotics_demo_msgs::ObjectPoseService > 
template<>
struct MD5Sum< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse>
{
  static const char* value()
  {
    return MD5Sum< ::unity_robotics_demo_msgs::ObjectPoseService >::value();
  }
  static const char* value(const ::unity_robotics_demo_msgs::ObjectPoseServiceResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse> should match 
// service_traits::DataType< ::unity_robotics_demo_msgs::ObjectPoseService > 
template<>
struct DataType< ::unity_robotics_demo_msgs::ObjectPoseServiceResponse>
{
  static const char* value()
  {
    return DataType< ::unity_robotics_demo_msgs::ObjectPoseService >::value();
  }
  static const char* value(const ::unity_robotics_demo_msgs::ObjectPoseServiceResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // UNITY_ROBOTICS_DEMO_MSGS_MESSAGE_OBJECTPOSESERVICE_H
