// Copyright 2019-2020 The MathWorks, Inc.
// Common copy functions for lwr_controllers/CartesianImpedancePoint
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
#include "lwr_controllers/CartesianImpedancePoint.h"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
COMMON_FW_DECLARE(lwr_controllers_msg_Stiffness_common, lwr_controllers::Stiffness)
class LWR_CONTROLLERS_EXPORT lwr_controllers_msg_CartesianImpedancePoint_common : public MATLABROSMsgInterface<lwr_controllers::CartesianImpedancePoint> {
  public:
    virtual ~lwr_controllers_msg_CartesianImpedancePoint_common(){}
    virtual void copy_from_struct(lwr_controllers::CartesianImpedancePoint* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const lwr_controllers::CartesianImpedancePoint* msg, MultiLibLoader loader, size_t size = 1);
};
  void lwr_controllers_msg_CartesianImpedancePoint_common::copy_from_struct(lwr_controllers::CartesianImpedancePoint* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //header
        const matlab::data::StructArray header_arr = arr["Header"];
        static auto msgClassPtr_header = loader->createInstance<MATLABROSMsgInterface<std_msgs::Header>>("std_msgs_msg_Header_common");
        msgClassPtr_header->copy_from_struct(&msg->header,header_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Header' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Header' is wrong type; expected a struct.");
    }
    try {
        //x_FRI
        const matlab::data::StructArray x_FRI_arr = arr["XFRI"];
        static auto msgClassPtr_x_FRI = loader->createInstance<MATLABROSMsgInterface<geometry_msgs::Pose>>("geometry_msgs_msg_Pose_common");
        msgClassPtr_x_FRI->copy_from_struct(&msg->x_FRI,x_FRI_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'XFRI' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'XFRI' is wrong type; expected a struct.");
    }
    try {
        //k_FRI
        const matlab::data::StructArray k_FRI_arr = arr["KFRI"];
        static lwr_controllers_msg_Stiffness_common obj_k_FRI;
        obj_k_FRI.copy_from_struct(&msg->k_FRI,k_FRI_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'KFRI' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'KFRI' is wrong type; expected a struct.");
    }
    try {
        //d_FRI
        const matlab::data::StructArray d_FRI_arr = arr["DFRI"];
        static lwr_controllers_msg_Stiffness_common obj_d_FRI;
        obj_d_FRI.copy_from_struct(&msg->d_FRI,d_FRI_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DFRI' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DFRI' is wrong type; expected a struct.");
    }
    try {
        //f_FRI
        const matlab::data::StructArray f_FRI_arr = arr["FFRI"];
        static auto msgClassPtr_f_FRI = loader->createInstance<MATLABROSMsgInterface<geometry_msgs::Wrench>>("geometry_msgs_msg_Wrench_common");
        msgClassPtr_f_FRI->copy_from_struct(&msg->f_FRI,f_FRI_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'FFRI' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'FFRI' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T lwr_controllers_msg_CartesianImpedancePoint_common::get_arr(MDFactory_T& factory, const lwr_controllers::CartesianImpedancePoint* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","XFRI","KFRI","DFRI","FFRI"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("lwr_controllers/CartesianImpedancePoint");
    // header
    auto currentElement_header = (msg + ctr)->header;
    static auto msgClassPtr_header = loader->createInstance<MATLABROSMsgInterface<std_msgs::Header>>("std_msgs_msg_Header_common");
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // x_FRI
    auto currentElement_x_FRI = (msg + ctr)->x_FRI;
    static auto msgClassPtr_x_FRI = loader->createInstance<MATLABROSMsgInterface<geometry_msgs::Pose>>("geometry_msgs_msg_Pose_common");
    outArray[ctr]["XFRI"] = msgClassPtr_x_FRI->get_arr(factory, &currentElement_x_FRI, loader);
    // k_FRI
    auto currentElement_k_FRI = (msg + ctr)->k_FRI;
    static lwr_controllers_msg_Stiffness_common obj_k_FRI;
    outArray[ctr]["KFRI"] = obj_k_FRI.get_arr(factory, &currentElement_k_FRI, loader);
    // d_FRI
    auto currentElement_d_FRI = (msg + ctr)->d_FRI;
    static lwr_controllers_msg_Stiffness_common obj_d_FRI;
    outArray[ctr]["DFRI"] = obj_d_FRI.get_arr(factory, &currentElement_d_FRI, loader);
    // f_FRI
    auto currentElement_f_FRI = (msg + ctr)->f_FRI;
    static auto msgClassPtr_f_FRI = loader->createInstance<MATLABROSMsgInterface<geometry_msgs::Wrench>>("geometry_msgs_msg_Wrench_common");
    outArray[ctr]["FFRI"] = msgClassPtr_f_FRI->get_arr(factory, &currentElement_f_FRI, loader);
    }
    return std::move(outArray);
  } 
class LWR_CONTROLLERS_EXPORT lwr_controllers_CartesianImpedancePoint_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~lwr_controllers_CartesianImpedancePoint_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          lwr_controllers_CartesianImpedancePoint_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<lwr_controllers::CartesianImpedancePoint,lwr_controllers_msg_CartesianImpedancePoint_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         lwr_controllers_CartesianImpedancePoint_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<lwr_controllers::CartesianImpedancePoint,lwr_controllers::CartesianImpedancePoint::ConstPtr,lwr_controllers_msg_CartesianImpedancePoint_common>>();
  }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_msg_CartesianImpedancePoint_common, MATLABROSMsgInterface<lwr_controllers::CartesianImpedancePoint>)
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_CartesianImpedancePoint_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1