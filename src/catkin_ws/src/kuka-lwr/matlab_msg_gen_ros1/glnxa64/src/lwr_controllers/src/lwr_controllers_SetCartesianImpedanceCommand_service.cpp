// Copyright 2019-2020 The MathWorks, Inc.
// Common copy functions for lwr_controllers/SetCartesianImpedanceCommandRequest
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
#include "lwr_controllers/SetCartesianImpedanceCommand.h"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROSPubSubTemplates.hpp"
#include "ROSServiceTemplates.hpp"
COMMON_FW_DECLARE(lwr_controllers_msg_CartesianImpedancePoint_common, lwr_controllers::CartesianImpedancePoint)
class LWR_CONTROLLERS_EXPORT lwr_controllers_msg_SetCartesianImpedanceCommandRequest_common : public MATLABROSMsgInterface<lwr_controllers::SetCartesianImpedanceCommand::Request> {
  public:
    virtual ~lwr_controllers_msg_SetCartesianImpedanceCommandRequest_common(){}
    virtual void copy_from_struct(lwr_controllers::SetCartesianImpedanceCommand::Request* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const lwr_controllers::SetCartesianImpedanceCommand::Request* msg, MultiLibLoader loader, size_t size = 1);
};
  void lwr_controllers_msg_SetCartesianImpedanceCommandRequest_common::copy_from_struct(lwr_controllers::SetCartesianImpedanceCommand::Request* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //command
        const matlab::data::StructArray command_arr = arr["Command"];
        static lwr_controllers_msg_CartesianImpedancePoint_common obj_command;
        obj_command.copy_from_struct(&msg->command,command_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Command' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Command' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T lwr_controllers_msg_SetCartesianImpedanceCommandRequest_common::get_arr(MDFactory_T& factory, const lwr_controllers::SetCartesianImpedanceCommand::Request* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Command"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("lwr_controllers/SetCartesianImpedanceCommandRequest");
    // command
    auto currentElement_command = (msg + ctr)->command;
    static lwr_controllers_msg_CartesianImpedancePoint_common obj_command;
    outArray[ctr]["Command"] = obj_command.get_arr(factory, &currentElement_command, loader);
    }
    return std::move(outArray);
  }
class LWR_CONTROLLERS_EXPORT lwr_controllers_msg_SetCartesianImpedanceCommandResponse_common : public MATLABROSMsgInterface<lwr_controllers::SetCartesianImpedanceCommand::Response> {
  public:
    virtual ~lwr_controllers_msg_SetCartesianImpedanceCommandResponse_common(){}
    virtual void copy_from_struct(lwr_controllers::SetCartesianImpedanceCommand::Response* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const lwr_controllers::SetCartesianImpedanceCommand::Response* msg, MultiLibLoader loader, size_t size = 1);
};
  void lwr_controllers_msg_SetCartesianImpedanceCommandResponse_common::copy_from_struct(lwr_controllers::SetCartesianImpedanceCommand::Response* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
  }
  //----------------------------------------------------------------------------
  MDArray_T lwr_controllers_msg_SetCartesianImpedanceCommandResponse_common::get_arr(MDFactory_T& factory, const lwr_controllers::SetCartesianImpedanceCommand::Response* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("lwr_controllers/SetCartesianImpedanceCommandResponse");
    }
    return std::move(outArray);
  } 
class LWR_CONTROLLERS_EXPORT lwr_controllers_SetCartesianImpedanceCommand_service : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~lwr_controllers_SetCartesianImpedanceCommand_service(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABSvcServerInterface> generateSvcServerInterface();
    virtual std::shared_ptr<MATLABSvcClientInterface> generateSvcClientInterface();
};  
  std::shared_ptr<MATLABPublisherInterface> 
          lwr_controllers_SetCartesianImpedanceCommand_service::generatePublisherInterface(ElementType type){
    std::shared_ptr<MATLABPublisherInterface> ptr;
    if(type == eRequest){
        ptr = std::make_shared<ROSPublisherImpl<lwr_controllers::SetCartesianImpedanceCommand::Request,lwr_controllers_msg_SetCartesianImpedanceCommandRequest_common>>();
    }else if(type == eResponse){
        ptr = std::make_shared<ROSPublisherImpl<lwr_controllers::SetCartesianImpedanceCommand::Response,lwr_controllers_msg_SetCartesianImpedanceCommandResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
    return ptr;
  }
  std::shared_ptr<MATLABSubscriberInterface> 
          lwr_controllers_SetCartesianImpedanceCommand_service::generateSubscriberInterface(ElementType type){
    std::shared_ptr<MATLABSubscriberInterface> ptr;
    if(type == eRequest){
        ptr = std::make_shared<ROSSubscriberImpl<lwr_controllers::SetCartesianImpedanceCommand::Request,lwr_controllers::SetCartesianImpedanceCommand::Request::ConstPtr,lwr_controllers_msg_SetCartesianImpedanceCommandRequest_common>>();
    }else if(type == eResponse){
        ptr = std::make_shared<ROSSubscriberImpl<lwr_controllers::SetCartesianImpedanceCommand::Response,lwr_controllers::SetCartesianImpedanceCommand::Response::ConstPtr,lwr_controllers_msg_SetCartesianImpedanceCommandResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
    return ptr;
  }
  std::shared_ptr<MATLABSvcServerInterface> 
          lwr_controllers_SetCartesianImpedanceCommand_service::generateSvcServerInterface(){
    return std::make_shared<ROSSvcServerImpl<lwr_controllers::SetCartesianImpedanceCommand::Request,lwr_controllers::SetCartesianImpedanceCommand::Response,lwr_controllers_msg_SetCartesianImpedanceCommandRequest_common,lwr_controllers_msg_SetCartesianImpedanceCommandResponse_common>>();
  }
  std::shared_ptr<MATLABSvcClientInterface> 
          lwr_controllers_SetCartesianImpedanceCommand_service::generateSvcClientInterface(){
    return std::make_shared<ROSSvcClientImpl<lwr_controllers::SetCartesianImpedanceCommand,lwr_controllers::SetCartesianImpedanceCommand::Request,lwr_controllers::SetCartesianImpedanceCommand::Response,lwr_controllers_msg_SetCartesianImpedanceCommandRequest_common,lwr_controllers_msg_SetCartesianImpedanceCommandResponse_common>>();
  }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_msg_SetCartesianImpedanceCommandRequest_common, MATLABROSMsgInterface<lwr_controllers::SetCartesianImpedanceCommand::Request>)
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_msg_SetCartesianImpedanceCommandResponse_common, MATLABROSMsgInterface<lwr_controllers::SetCartesianImpedanceCommand::Response>)
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_SetCartesianImpedanceCommand_service, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
