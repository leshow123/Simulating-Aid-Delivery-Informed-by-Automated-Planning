// Generated by gencpp from file rosplan_knowledge_msgs/KnowledgeQueryService.msg
// DO NOT EDIT!


#ifndef ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_KNOWLEDGEQUERYSERVICE_H
#define ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_KNOWLEDGEQUERYSERVICE_H

#include <ros/service_traits.h>


#include <rosplan_knowledge_msgs/KnowledgeQueryServiceRequest.h>
#include <rosplan_knowledge_msgs/KnowledgeQueryServiceResponse.h>


namespace rosplan_knowledge_msgs
{

struct KnowledgeQueryService
{

typedef KnowledgeQueryServiceRequest Request;
typedef KnowledgeQueryServiceResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct KnowledgeQueryService
} // namespace rosplan_knowledge_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::rosplan_knowledge_msgs::KnowledgeQueryService > {
  static const char* value()
  {
    return "e5cd9298f5a545040e7835836f3210cb";
  }

  static const char* value(const ::rosplan_knowledge_msgs::KnowledgeQueryService&) { return value(); }
};

template<>
struct DataType< ::rosplan_knowledge_msgs::KnowledgeQueryService > {
  static const char* value()
  {
    return "rosplan_knowledge_msgs/KnowledgeQueryService";
  }

  static const char* value(const ::rosplan_knowledge_msgs::KnowledgeQueryService&) { return value(); }
};


// service_traits::MD5Sum< ::rosplan_knowledge_msgs::KnowledgeQueryServiceRequest> should match 
// service_traits::MD5Sum< ::rosplan_knowledge_msgs::KnowledgeQueryService > 
template<>
struct MD5Sum< ::rosplan_knowledge_msgs::KnowledgeQueryServiceRequest>
{
  static const char* value()
  {
    return MD5Sum< ::rosplan_knowledge_msgs::KnowledgeQueryService >::value();
  }
  static const char* value(const ::rosplan_knowledge_msgs::KnowledgeQueryServiceRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::rosplan_knowledge_msgs::KnowledgeQueryServiceRequest> should match 
// service_traits::DataType< ::rosplan_knowledge_msgs::KnowledgeQueryService > 
template<>
struct DataType< ::rosplan_knowledge_msgs::KnowledgeQueryServiceRequest>
{
  static const char* value()
  {
    return DataType< ::rosplan_knowledge_msgs::KnowledgeQueryService >::value();
  }
  static const char* value(const ::rosplan_knowledge_msgs::KnowledgeQueryServiceRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::rosplan_knowledge_msgs::KnowledgeQueryServiceResponse> should match 
// service_traits::MD5Sum< ::rosplan_knowledge_msgs::KnowledgeQueryService > 
template<>
struct MD5Sum< ::rosplan_knowledge_msgs::KnowledgeQueryServiceResponse>
{
  static const char* value()
  {
    return MD5Sum< ::rosplan_knowledge_msgs::KnowledgeQueryService >::value();
  }
  static const char* value(const ::rosplan_knowledge_msgs::KnowledgeQueryServiceResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::rosplan_knowledge_msgs::KnowledgeQueryServiceResponse> should match 
// service_traits::DataType< ::rosplan_knowledge_msgs::KnowledgeQueryService > 
template<>
struct DataType< ::rosplan_knowledge_msgs::KnowledgeQueryServiceResponse>
{
  static const char* value()
  {
    return DataType< ::rosplan_knowledge_msgs::KnowledgeQueryService >::value();
  }
  static const char* value(const ::rosplan_knowledge_msgs::KnowledgeQueryServiceResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ROSPLAN_KNOWLEDGE_MSGS_MESSAGE_KNOWLEDGEQUERYSERVICE_H