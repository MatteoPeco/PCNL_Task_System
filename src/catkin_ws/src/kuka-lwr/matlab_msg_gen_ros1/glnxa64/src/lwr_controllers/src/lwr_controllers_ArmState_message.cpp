// Copyright 2019-2020 The MathWorks, Inc.
// Common copy functions for lwr_controllers/ArmState
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
#include "lwr_controllers/ArmState.h"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class LWR_CONTROLLERS_EXPORT lwr_controllers_msg_ArmState_common : public MATLABROSMsgInterface<lwr_controllers::ArmState> {
  public:
    virtual ~lwr_controllers_msg_ArmState_common(){}
    virtual void copy_from_struct(lwr_controllers::ArmState* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const lwr_controllers::ArmState* msg, MultiLibLoader loader, size_t size = 1);
};
  void lwr_controllers_msg_ArmState_common::copy_from_struct(lwr_controllers::ArmState* msg, const matlab::data::Struct& arr,
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
        //joint_name
        const matlab::data::CellArray joint_name_cellarr = arr["JointName"];
        size_t nelem = joint_name_cellarr.getNumberOfElements();
        for (size_t idx=0; idx < nelem; ++idx){
        	const matlab::data::CharArray joint_name_arr = joint_name_cellarr[idx];
        	msg->joint_name.push_back(joint_name_arr.toAscii());
        }
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'JointName' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'JointName' is wrong type; expected a string.");
    }
    try {
        //est_ext_torques
        const matlab::data::TypedArray<float> est_ext_torques_arr = arr["EstExtTorques"];
        size_t nelem = est_ext_torques_arr.getNumberOfElements();
        	msg->est_ext_torques.resize(nelem);
        	std::copy(est_ext_torques_arr.begin(), est_ext_torques_arr.begin()+nelem, msg->est_ext_torques.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'EstExtTorques' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'EstExtTorques' is wrong type; expected a single.");
    }
    try {
        //est_ee_wrench
        const matlab::data::StructArray est_ee_wrench_arr = arr["EstEeWrench"];
        static auto msgClassPtr_est_ee_wrench = loader->createInstance<MATLABROSMsgInterface<geometry_msgs::Wrench>>("geometry_msgs_msg_Wrench_common");
        msgClassPtr_est_ee_wrench->copy_from_struct(&msg->est_ee_wrench,est_ee_wrench_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'EstEeWrench' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'EstEeWrench' is wrong type; expected a struct.");
    }
    try {
        //est_ee_wrench_base
        const matlab::data::StructArray est_ee_wrench_base_arr = arr["EstEeWrenchBase"];
        static auto msgClassPtr_est_ee_wrench_base = loader->createInstance<MATLABROSMsgInterface<geometry_msgs::Wrench>>("geometry_msgs_msg_Wrench_common");
        msgClassPtr_est_ee_wrench_base->copy_from_struct(&msg->est_ee_wrench_base,est_ee_wrench_base_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'EstEeWrenchBase' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'EstEeWrenchBase' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T lwr_controllers_msg_ArmState_common::get_arr(MDFactory_T& factory, const lwr_controllers::ArmState* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","JointName","EstExtTorques","EstEeWrench","EstEeWrenchBase"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("lwr_controllers/ArmState");
    // header
    auto currentElement_header = (msg + ctr)->header;
    static auto msgClassPtr_header = loader->createInstance<MATLABROSMsgInterface<std_msgs::Header>>("std_msgs_msg_Header_common");
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // joint_name
    auto currentElement_joint_name = (msg + ctr)->joint_name;
    auto joint_nameoutCell = factory.createCellArray({currentElement_joint_name.size(),1});
    for(size_t idxin = 0; idxin < currentElement_joint_name.size(); ++ idxin){
    	joint_nameoutCell[idxin] = factory.createCharArray(currentElement_joint_name[idxin]);
    }
    outArray[ctr]["JointName"] = joint_nameoutCell;
    // est_ext_torques
    auto currentElement_est_ext_torques = (msg + ctr)->est_ext_torques;
    outArray[ctr]["EstExtTorques"] = factory.createArray<lwr_controllers::ArmState::_est_ext_torques_type::const_iterator, float>({currentElement_est_ext_torques.size(),1}, currentElement_est_ext_torques.begin(), currentElement_est_ext_torques.end());
    // est_ee_wrench
    auto currentElement_est_ee_wrench = (msg + ctr)->est_ee_wrench;
    static auto msgClassPtr_est_ee_wrench = loader->createInstance<MATLABROSMsgInterface<geometry_msgs::Wrench>>("geometry_msgs_msg_Wrench_common");
    outArray[ctr]["EstEeWrench"] = msgClassPtr_est_ee_wrench->get_arr(factory, &currentElement_est_ee_wrench, loader);
    // est_ee_wrench_base
    auto currentElement_est_ee_wrench_base = (msg + ctr)->est_ee_wrench_base;
    static auto msgClassPtr_est_ee_wrench_base = loader->createInstance<MATLABROSMsgInterface<geometry_msgs::Wrench>>("geometry_msgs_msg_Wrench_common");
    outArray[ctr]["EstEeWrenchBase"] = msgClassPtr_est_ee_wrench_base->get_arr(factory, &currentElement_est_ee_wrench_base, loader);
    }
    return std::move(outArray);
  } 
class LWR_CONTROLLERS_EXPORT lwr_controllers_ArmState_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~lwr_controllers_ArmState_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          lwr_controllers_ArmState_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<lwr_controllers::ArmState,lwr_controllers_msg_ArmState_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         lwr_controllers_ArmState_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<lwr_controllers::ArmState,lwr_controllers::ArmState::ConstPtr,lwr_controllers_msg_ArmState_common>>();
  }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_msg_ArmState_common, MATLABROSMsgInterface<lwr_controllers::ArmState>)
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_ArmState_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1