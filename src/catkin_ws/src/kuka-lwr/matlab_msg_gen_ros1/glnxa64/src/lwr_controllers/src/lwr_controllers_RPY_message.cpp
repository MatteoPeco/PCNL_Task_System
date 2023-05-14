// Copyright 2019-2020 The MathWorks, Inc.
// Common copy functions for lwr_controllers/RPY
#include "boost/date_time.hpp"
#include "boost/shared_array.hpp"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#pragma warning(disable : 4127)
#pragma warning(disable : 4267)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#endif //_MSC_VER
#include "ros/ros.h"
#include "lwr_controllers/RPY.h"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class LWR_CONTROLLERS_EXPORT lwr_controllers_msg_RPY_common : public MATLABROSMsgInterface<lwr_controllers::RPY> {
  public:
    virtual ~lwr_controllers_msg_RPY_common(){}
    virtual void copy_from_struct(lwr_controllers::RPY* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const lwr_controllers::RPY* msg, MultiLibLoader loader, size_t size = 1);
};
  void lwr_controllers_msg_RPY_common::copy_from_struct(lwr_controllers::RPY* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //roll
        const matlab::data::TypedArray<double> roll_arr = arr["Roll"];
        msg->roll = roll_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Roll' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Roll' is wrong type; expected a double.");
    }
    try {
        //pitch
        const matlab::data::TypedArray<double> pitch_arr = arr["Pitch"];
        msg->pitch = pitch_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Pitch' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Pitch' is wrong type; expected a double.");
    }
    try {
        //yaw
        const matlab::data::TypedArray<double> yaw_arr = arr["Yaw"];
        msg->yaw = yaw_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Yaw' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Yaw' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T lwr_controllers_msg_RPY_common::get_arr(MDFactory_T& factory, const lwr_controllers::RPY* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Roll","Pitch","Yaw"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("lwr_controllers/RPY");
    // roll
    auto currentElement_roll = (msg + ctr)->roll;
    outArray[ctr]["Roll"] = factory.createScalar(currentElement_roll);
    // pitch
    auto currentElement_pitch = (msg + ctr)->pitch;
    outArray[ctr]["Pitch"] = factory.createScalar(currentElement_pitch);
    // yaw
    auto currentElement_yaw = (msg + ctr)->yaw;
    outArray[ctr]["Yaw"] = factory.createScalar(currentElement_yaw);
    }
    return std::move(outArray);
  } 
class LWR_CONTROLLERS_EXPORT lwr_controllers_RPY_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~lwr_controllers_RPY_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          lwr_controllers_RPY_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<lwr_controllers::RPY,lwr_controllers_msg_RPY_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         lwr_controllers_RPY_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<lwr_controllers::RPY,lwr_controllers::RPY::ConstPtr,lwr_controllers_msg_RPY_common>>();
  }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_msg_RPY_common, MATLABROSMsgInterface<lwr_controllers::RPY>)
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_RPY_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1