// Copyright 2019-2020 The MathWorks, Inc.
// Common copy functions for lwr_controllers/PoseRPY
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
#include "lwr_controllers/PoseRPY.h"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
COMMON_FW_DECLARE(lwr_controllers_msg_RPY_common, lwr_controllers::RPY)
class LWR_CONTROLLERS_EXPORT lwr_controllers_msg_PoseRPY_common : public MATLABROSMsgInterface<lwr_controllers::PoseRPY> {
  public:
    virtual ~lwr_controllers_msg_PoseRPY_common(){}
    virtual void copy_from_struct(lwr_controllers::PoseRPY* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const lwr_controllers::PoseRPY* msg, MultiLibLoader loader, size_t size = 1);
};
  void lwr_controllers_msg_PoseRPY_common::copy_from_struct(lwr_controllers::PoseRPY* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //id
        const matlab::data::TypedArray<int32_t> id_arr = arr["Id"];
        msg->id = id_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Id' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Id' is wrong type; expected a int32.");
    }
    try {
        //position
        const matlab::data::StructArray position_arr = arr["Position"];
        static auto msgClassPtr_position = loader->createInstance<MATLABROSMsgInterface<geometry_msgs::Vector3>>("geometry_msgs_msg_Vector3_common");
        msgClassPtr_position->copy_from_struct(&msg->position,position_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Position' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Position' is wrong type; expected a struct.");
    }
    try {
        //orientation
        const matlab::data::StructArray orientation_arr = arr["Orientation"];
        static lwr_controllers_msg_RPY_common obj_orientation;
        obj_orientation.copy_from_struct(&msg->orientation,orientation_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Orientation' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Orientation' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T lwr_controllers_msg_PoseRPY_common::get_arr(MDFactory_T& factory, const lwr_controllers::PoseRPY* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Id","Position","Orientation"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("lwr_controllers/PoseRPY");
    // id
    auto currentElement_id = (msg + ctr)->id;
    outArray[ctr]["Id"] = factory.createScalar(currentElement_id);
    // position
    auto currentElement_position = (msg + ctr)->position;
    static auto msgClassPtr_position = loader->createInstance<MATLABROSMsgInterface<geometry_msgs::Vector3>>("geometry_msgs_msg_Vector3_common");
    outArray[ctr]["Position"] = msgClassPtr_position->get_arr(factory, &currentElement_position, loader);
    // orientation
    auto currentElement_orientation = (msg + ctr)->orientation;
    static lwr_controllers_msg_RPY_common obj_orientation;
    outArray[ctr]["Orientation"] = obj_orientation.get_arr(factory, &currentElement_orientation, loader);
    }
    return std::move(outArray);
  } 
class LWR_CONTROLLERS_EXPORT lwr_controllers_PoseRPY_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~lwr_controllers_PoseRPY_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          lwr_controllers_PoseRPY_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<lwr_controllers::PoseRPY,lwr_controllers_msg_PoseRPY_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         lwr_controllers_PoseRPY_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<lwr_controllers::PoseRPY,lwr_controllers::PoseRPY::ConstPtr,lwr_controllers_msg_PoseRPY_common>>();
  }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_msg_PoseRPY_common, MATLABROSMsgInterface<lwr_controllers::PoseRPY>)
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_PoseRPY_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1