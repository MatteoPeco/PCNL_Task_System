// Copyright 2019-2020 The MathWorks, Inc.
// Common copy functions for lwr_controllers/Stiffness
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
#include "lwr_controllers/Stiffness.h"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class LWR_CONTROLLERS_EXPORT lwr_controllers_msg_Stiffness_common : public MATLABROSMsgInterface<lwr_controllers::Stiffness> {
  public:
    virtual ~lwr_controllers_msg_Stiffness_common(){}
    virtual void copy_from_struct(lwr_controllers::Stiffness* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const lwr_controllers::Stiffness* msg, MultiLibLoader loader, size_t size = 1);
};
  void lwr_controllers_msg_Stiffness_common::copy_from_struct(lwr_controllers::Stiffness* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //x
        const matlab::data::TypedArray<double> x_arr = arr["X"];
        msg->x = x_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'X' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'X' is wrong type; expected a double.");
    }
    try {
        //y
        const matlab::data::TypedArray<double> y_arr = arr["Y"];
        msg->y = y_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Y' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Y' is wrong type; expected a double.");
    }
    try {
        //z
        const matlab::data::TypedArray<double> z_arr = arr["Z"];
        msg->z = z_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Z' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Z' is wrong type; expected a double.");
    }
    try {
        //rx
        const matlab::data::TypedArray<double> rx_arr = arr["Rx"];
        msg->rx = rx_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Rx' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Rx' is wrong type; expected a double.");
    }
    try {
        //ry
        const matlab::data::TypedArray<double> ry_arr = arr["Ry"];
        msg->ry = ry_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Ry' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Ry' is wrong type; expected a double.");
    }
    try {
        //rz
        const matlab::data::TypedArray<double> rz_arr = arr["Rz"];
        msg->rz = rz_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Rz' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Rz' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T lwr_controllers_msg_Stiffness_common::get_arr(MDFactory_T& factory, const lwr_controllers::Stiffness* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","X","Y","Z","Rx","Ry","Rz"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("lwr_controllers/Stiffness");
    // x
    auto currentElement_x = (msg + ctr)->x;
    outArray[ctr]["X"] = factory.createScalar(currentElement_x);
    // y
    auto currentElement_y = (msg + ctr)->y;
    outArray[ctr]["Y"] = factory.createScalar(currentElement_y);
    // z
    auto currentElement_z = (msg + ctr)->z;
    outArray[ctr]["Z"] = factory.createScalar(currentElement_z);
    // rx
    auto currentElement_rx = (msg + ctr)->rx;
    outArray[ctr]["Rx"] = factory.createScalar(currentElement_rx);
    // ry
    auto currentElement_ry = (msg + ctr)->ry;
    outArray[ctr]["Ry"] = factory.createScalar(currentElement_ry);
    // rz
    auto currentElement_rz = (msg + ctr)->rz;
    outArray[ctr]["Rz"] = factory.createScalar(currentElement_rz);
    }
    return std::move(outArray);
  } 
class LWR_CONTROLLERS_EXPORT lwr_controllers_Stiffness_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~lwr_controllers_Stiffness_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          lwr_controllers_Stiffness_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<lwr_controllers::Stiffness,lwr_controllers_msg_Stiffness_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         lwr_controllers_Stiffness_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<lwr_controllers::Stiffness,lwr_controllers::Stiffness::ConstPtr,lwr_controllers_msg_Stiffness_common>>();
  }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_msg_Stiffness_common, MATLABROSMsgInterface<lwr_controllers::Stiffness>)
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_Stiffness_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1