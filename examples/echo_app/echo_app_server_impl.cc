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

using daprclient::InvokeEnvelope;
using daprclient::GetTopicSubscriptionsEnvelope;
using daprclient::GetBindingsSubscriptionsEnvelope;
using daprclient::BindingEventEnvelope;
using daprclient::BindingResponseEnvelope;
using daprclient::CloudEventEnvelope;

namespace dapr_cpp_echo_example {

Status EchoAppServerImpl::OnInvoke(
  ServerContext* context,
  const InvokeEnvelope* request,
  Any* response) {
  
  std::cout << "OnInvoke() is called"  << std::endl;

  if (request->method() == "echo") {
    std::cout << "Got the message: " << request->data().value() << std::endl;
    std::string resp_str = "ack : " + request->data().value();
    response->mutable_value()->assign(resp_str);
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
