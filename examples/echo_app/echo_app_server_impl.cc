// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
// ------------------------------------------------------------

#include <iostream>
#include <memory>
#include <string>

#include "echo_app_server_impl.h"

using grpc::ServerContext;
using grpc::Status;

using google::protobuf::Any;
using google::protobuf::Empty;

using dapr::proto::common::v1::InvokeRequest;
using dapr::proto::common::v1::InvokeResponse;
using dapr::proto::daprclient::v1::GetTopicSubscriptionsEnvelope;
using dapr::proto::daprclient::v1::GetBindingsSubscriptionsEnvelope;
using dapr::proto::daprclient::v1::BindingEventEnvelope;
using dapr::proto::daprclient::v1::BindingResponseEnvelope;
using dapr::proto::daprclient::v1::CloudEventEnvelope;

namespace dapr_cpp_echo_example {

Status EchoAppServerImpl::OnInvoke(
  ServerContext* context,
  const InvokeRequest* request,
  InvokeResponse* response) {
  
  std::cout << "OnInvoke() is called"  << std::endl;

  if (request->method() == "echo") {
    std::cout << "Got the message: " << request->data().value() << std::endl;
    std::string resp_str = "ack : " + request->data().value();
    response->mutable_data()->set_value(resp_str);
  }

  return Status::OK;
}

Status EchoAppServerImpl::GetTopicSubscriptions(
  ServerContext* context,
  const Empty* request,
  GetTopicSubscriptionsEnvelope* response)  {
  std::cout << "GetTopicSubscriptions() is called"  << std::endl;
  return Status::OK;
}

Status EchoAppServerImpl::GetBindingsSubscriptions(
  ServerContext* context,
  const Empty* request,
  GetBindingsSubscriptionsEnvelope* response)  {
  std::cout << "GetBindingsSubscriptions() is called" << std::endl;
  return Status::OK;
}

Status EchoAppServerImpl::OnBindingEvent(
  ServerContext* context,
  const BindingEventEnvelope* request,
  BindingResponseEnvelope* response)  {
  std::cout << "OnBindingEvent() is called"  << std::endl;
  return Status::OK;
}

Status EchoAppServerImpl::OnTopicEvent(
  ServerContext* context,
  const CloudEventEnvelope* request,
  Empty* response)  {
  std::cout << "OnBindingEvent() is called"  << std::endl;
  return Status::OK;
}

} // namespace dapr_cpp_echo_example
