// Copyright 2019-2020 The MathWorks, Inc.
// Common copy functions for lwr_controllers/MultiPriorityTask
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
#include "lwr_controllers/MultiPriorityTask.h"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class LWR_CONTROLLERS_EXPORT lwr_controllers_msg_MultiPriorityTask_common : public MATLABROSMsgInterface<lwr_controllers::MultiPriorityTask> {
  public:
    virtual ~lwr_controllers_msg_MultiPriorityTask_common(){}
    virtual void copy_from_struct(lwr_controllers::MultiPriorityTask* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const lwr_controllers::MultiPriorityTask* msg, MultiLibLoader loader, size_t size = 1);
};
  void lwr_controllers_msg_MultiPriorityTask_common::copy_from_struct(lwr_controllers::MultiPriorityTask* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //links
        const matlab::data::TypedArray<int32_t> links_arr = arr["Links"];
        size_t nelem = links_arr.getNumberOfElements();
        	msg->links.resize(nelem);
        	std::copy(links_arr.begin(), links_arr.begin()+nelem, msg->links.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Links' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Links' is wrong type; expected a int32.");
    }
    try {
        //tasks
        const matlab::data::TypedArray<double> tasks_arr = arr["Tasks"];
        size_t nelem = tasks_arr.getNumberOfElements();
        	msg->tasks.resize(nelem);
        	std::copy(tasks_arr.begin(), tasks_arr.begin()+nelem, msg->tasks.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Tasks' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Tasks' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T lwr_controllers_msg_MultiPriorityTask_common::get_arr(MDFactory_T& factory, const lwr_controllers::MultiPriorityTask* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Links","Tasks"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("lwr_controllers/MultiPriorityTask");
    // links
    auto currentElement_links = (msg + ctr)->links;
    outArray[ctr]["Links"] = factory.createArray<lwr_controllers::MultiPriorityTask::_links_type::const_iterator, int32_t>({currentElement_links.size(),1}, currentElement_links.begin(), currentElement_links.end());
    // tasks
    auto currentElement_tasks = (msg + ctr)->tasks;
    outArray[ctr]["Tasks"] = factory.createArray<lwr_controllers::MultiPriorityTask::_tasks_type::const_iterator, double>({currentElement_tasks.size(),1}, currentElement_tasks.begin(), currentElement_tasks.end());
    }
    return std::move(outArray);
  } 
class LWR_CONTROLLERS_EXPORT lwr_controllers_MultiPriorityTask_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~lwr_controllers_MultiPriorityTask_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          lwr_controllers_MultiPriorityTask_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<lwr_controllers::MultiPriorityTask,lwr_controllers_msg_MultiPriorityTask_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         lwr_controllers_MultiPriorityTask_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<lwr_controllers::MultiPriorityTask,lwr_controllers::MultiPriorityTask::ConstPtr,lwr_controllers_msg_MultiPriorityTask_common>>();
  }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_msg_MultiPriorityTask_common, MATLABROSMsgInterface<lwr_controllers::MultiPriorityTask>)
CLASS_LOADER_REGISTER_CLASS(lwr_controllers_MultiPriorityTask_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1