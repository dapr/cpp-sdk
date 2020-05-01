// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
// ------------------------------------------------------------

#include <grpcpp/grpcpp.h>

#include "dapr/proto/common/v1/common.pb.h"
#include "dapr/proto/daprclient/v1/daprclient.grpc.pb.h"

using grpc::ServerContext;
using grpc::Status;

using google::protobuf::Any;
using google::protobuf::Empty;

using dapr::proto::common::v1::InvokeRequest;
using dapr::proto::common::v1::InvokeResponse;
using dapr::proto::daprclient::v1::DaprClient;
using dapr::proto::daprclient::v1::GetTopicSubscriptionsEnvelope;
using dapr::proto::daprclient::v1::GetBindingsSubscriptionsEnvelope;
using dapr::proto::daprclient::v1::BindingEventEnvelope;
using dapr::proto::daprclient::v1::BindingResponseEnvelope;
using dapr::proto::daprclient::v1::CloudEventEnvelope;

namespace dapr_cpp_echo_example {
  
class EchoAppServerImpl final : public DaprClient::Service {
  public:
    Status OnInvoke(ServerContext* context, const InvokeRequest* request, InvokeResponse* response) override;
    Status GetTopicSubscriptions(ServerContext* context, const Empty* request, GetTopicSubscriptionsEnvelope* response) override;
    Status GetBindingsSubscriptions(ServerContext* context, const Empty* request, GetBindingsSubscriptionsEnvelope* response) override;
    Status OnBindingEvent(ServerContext* context, const BindingEventEnvelope* request, BindingResponseEnvelope* response) override;
    Status OnTopicEvent(ServerContext* context, const CloudEventEnvelope* request, Empty* response) override;
};

} // namespace dapr_cpp_echo_example
