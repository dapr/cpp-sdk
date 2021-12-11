// ------------------------------------------------------------------------
// Copyright 2021 The Dapr Authors
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//     http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ------------------------------------------------------------------------

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
using dapr::proto::runtime::v1::ListTopicSubscriptionsResponse;
using dapr::proto::runtime::v1::ListInputBindingsResponse;
using dapr::proto::runtime::v1::BindingEventRequest;
using dapr::proto::runtime::v1::BindingEventResponse;
using dapr::proto::runtime::v1::TopicEventRequest;
using dapr::proto::runtime::v1::TopicEventResponse;

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

Status EchoAppServerImpl::ListTopicSubscriptions(
  ServerContext* context,
  const Empty* request,
  ListTopicSubscriptionsResponse* response)  {
  std::cout << "ListTopicSubscriptions() is called"  << std::endl;
  return Status::OK;
}

Status EchoAppServerImpl::ListInputBindings(
  ServerContext* context,
  const Empty* request,
  ListInputBindingsResponse* response)  {
  std::cout << "ListInputBindings() is called" << std::endl;
  return Status::OK;
}

Status EchoAppServerImpl::OnBindingEvent(
  ServerContext* context,
  const BindingEventRequest* request,
  BindingEventResponse* response)  {
  std::cout << "OnBindingEvent() is called"  << std::endl;
  return Status::OK;
}

Status EchoAppServerImpl::OnTopicEvent(
  ServerContext* context,
  const TopicEventRequest* request,
  TopicEventResponse* response)  {
  std::cout << "OnBindingEvent() is called"  << std::endl;
  return Status::OK;
}

} // namespace dapr_cpp_echo_example
