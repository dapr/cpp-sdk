#include <grpc++/grpc++.h>

#include "../../src/daprclient/daprclient.grpc.pb.h"

using grpc::ServerContext;
using grpc::Status;

using google::protobuf::Any;
using google::protobuf::Empty;

using daprclient::DaprClient;
using daprclient::InvokeEnvelope;
using daprclient::GetTopicSubscriptionsEnvelope;
using daprclient::GetBindingsSubscriptionsEnvelope;
using daprclient::BindingEventEnvelope;
using daprclient::BindingResponseEnvelope;
using daprclient::CloudEventEnvelope;

namespace dapr_cpp_echo_example {
  
class EchoAppServerImpl final : public DaprClient::Service {
  Status OnInvoke(ServerContext* context, const InvokeEnvelope* request, Any* response) override;
  Status GetTopicSubscriptions(ServerContext* context, const Empty* request, GetTopicSubscriptionsEnvelope* response) override;
  Status GetBindingsSubscriptions(ServerContext* context, const Empty* request, GetBindingsSubscriptionsEnvelope* response) override;
  Status OnBindingEvent(ServerContext* context, const BindingEventEnvelope* request, BindingResponseEnvelope* response) override;
  Status OnTopicEvent(ServerContext* context, const CloudEventEnvelope* request, Empty* response) override;
};

} // namespace dapr_cpp_echo_example
