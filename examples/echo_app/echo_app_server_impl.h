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

#include <grpcpp/grpcpp.h>

#include "dapr/proto/common/v1/common.pb.h"
#include "dapr/proto/runtime/v1/appcallback.grpc.pb.h"

using grpc::ServerContext;
using grpc::Status;

using google::protobuf::Any;
using google::protobuf::Empty;

using dapr::proto::common::v1::InvokeRequest;
using dapr::proto::common::v1::InvokeResponse;
using dapr::proto::runtime::v1::AppCallback;
using dapr::proto::runtime::v1::ListTopicSubscriptionsResponse;
using dapr::proto::runtime::v1::ListInputBindingsResponse;
using dapr::proto::runtime::v1::BindingEventRequest;
using dapr::proto::runtime::v1::BindingEventResponse;
using dapr::proto::runtime::v1::TopicEventRequest;
using dapr::proto::runtime::v1::TopicEventResponse;

namespace dapr_cpp_echo_example {
  
class EchoAppServerImpl final : public AppCallback::Service {
  public:
    Status OnInvoke(ServerContext* context, const InvokeRequest* request, InvokeResponse* response) override;
    Status ListTopicSubscriptions(ServerContext* context, const Empty* request, ListTopicSubscriptionsResponse* response) override;
    Status ListInputBindings(ServerContext* context, const Empty* request, ListInputBindingsResponse* response) override;
    Status OnBindingEvent(ServerContext* context, const BindingEventRequest* request, BindingEventResponse* response) override;
    Status OnTopicEvent(ServerContext* context, const TopicEventRequest* request, TopicEventResponse* response) override;
};

} // namespace dapr_cpp_echo_example
