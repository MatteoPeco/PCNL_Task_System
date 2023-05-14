// Generated by gencpp from file lwr_controllers/SetCartesianImpedanceCommand.msg
// DO NOT EDIT!


#ifndef LWR_CONTROLLERS_MESSAGE_SETCARTESIANIMPEDANCECOMMAND_H
#define LWR_CONTROLLERS_MESSAGE_SETCARTESIANIMPEDANCECOMMAND_H

#include <ros/service_traits.h>


#include <lwr_controllers/SetCartesianImpedanceCommandRequest.h>
#include <lwr_controllers/SetCartesianImpedanceCommandResponse.h>


namespace lwr_controllers
{

struct SetCartesianImpedanceCommand
{

typedef SetCartesianImpedanceCommandRequest Request;
typedef SetCartesianImpedanceCommandResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetCartesianImpedanceCommand
} // namespace lwr_controllers


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::lwr_controllers::SetCartesianImpedanceCommand > {
  static const char* value()
  {
    return "cc36264319f44d204c2ace0744aa21ee";
  }

  static const char* value(const ::lwr_controllers::SetCartesianImpedanceCommand&) { return value(); }
};

template<>
struct DataType< ::lwr_controllers::SetCartesianImpedanceCommand > {
  static const char* value()
  {
    return "lwr_controllers/SetCartesianImpedanceCommand";
  }

  static const char* value(const ::lwr_controllers::SetCartesianImpedanceCommand&) { return value(); }
};


// service_traits::MD5Sum< ::lwr_controllers::SetCartesianImpedanceCommandRequest> should match 
// service_traits::MD5Sum< ::lwr_controllers::SetCartesianImpedanceCommand > 
template<>
struct MD5Sum< ::lwr_controllers::SetCartesianImpedanceCommandRequest>
{
  static const char* value()
  {
    return MD5Sum< ::lwr_controllers::SetCartesianImpedanceCommand >::value();
  }
  static const char* value(const ::lwr_controllers::SetCartesianImpedanceCommandRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::lwr_controllers::SetCartesianImpedanceCommandRequest> should match 
// service_traits::DataType< ::lwr_controllers::SetCartesianImpedanceCommand > 
template<>
struct DataType< ::lwr_controllers::SetCartesianImpedanceCommandRequest>
{
  static const char* value()
  {
    return DataType< ::lwr_controllers::SetCartesianImpedanceCommand >::value();
  }
  static const char* value(const ::lwr_controllers::SetCartesianImpedanceCommandRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::lwr_controllers::SetCartesianImpedanceCommandResponse> should match 
// service_traits::MD5Sum< ::lwr_controllers::SetCartesianImpedanceCommand > 
template<>
struct MD5Sum< ::lwr_controllers::SetCartesianImpedanceCommandResponse>
{
  static const char* value()
  {
    return MD5Sum< ::lwr_controllers::SetCartesianImpedanceCommand >::value();
  }
  static const char* value(const ::lwr_controllers::SetCartesianImpedanceCommandResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::lwr_controllers::SetCartesianImpedanceCommandResponse> should match 
// service_traits::DataType< ::lwr_controllers::SetCartesianImpedanceCommand > 
template<>
struct DataType< ::lwr_controllers::SetCartesianImpedanceCommandResponse>
{
  static const char* value()
  {
    return DataType< ::lwr_controllers::SetCartesianImpedanceCommand >::value();
  }
  static const char* value(const ::lwr_controllers::SetCartesianImpedanceCommandResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // LWR_CONTROLLERS_MESSAGE_SETCARTESIANIMPEDANCECOMMAND_H