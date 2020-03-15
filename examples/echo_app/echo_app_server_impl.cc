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

Status EchoAppServerImpl::OnInvoke(ServerContext* context, const InvokeEnvelope* request, Any* response) {
  return Status::OK;
}

Status EchoAppServerImpl::GetTopicSubscriptions(ServerContext* context, const Empty* request, GetTopicSubscriptionsEnvelope* response)  {
  return Status::OK;
}

Status EchoAppServerImpl::GetBindingsSubscriptions(ServerContext* context, const Empty* request, GetBindingsSubscriptionsEnvelope* response)  {
  return Status::OK;
}

Status EchoAppServerImpl::OnBindingEvent(ServerContext* context, const BindingEventEnvelope* request, BindingResponseEnvelope* response)  {
  return Status::OK;
}

Status EchoAppServerImpl::OnTopicEvent(ServerContext* context, const CloudEventEnvelope* request, Empty* response)  {
  return Status::OK;
}

} // namespace dapr_cpp_echo_example
