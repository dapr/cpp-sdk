#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "echo_app_server_impl.h"
#include "../../src/dapr/dapr.grpc.pb.h"

using dapr::Dapr;

using grpc::Channel;
using grpc::ClientContext;
using grpc::ServerBuilder;
using grpc::Status;
using grpc::Server;

using google::protobuf::Any;

namespace dapr_cpp_echo_example {

class EchoApp {
  public:
    EchoApp() {}

    void Initialize() {
      client_stub_ = Dapr::NewStub(grpc::CreateChannel(dapr_grpc_endpoint(), grpc::InsecureChannelCredentials()));
    }

    std::string EchoMessage(
      const std::string& app_id,
      const std::string& method,
      const std::string& message) {
      ClientContext context;
      dapr::InvokeServiceEnvelope request;
      dapr::InvokeServiceResponseEnvelope response;

      // Pack value into protobuf::Any
      google::protobuf::Any value;
      value.ParseFromString(message);

      // Construct service invocation request
      request.set_id(app_id);
      request.set_method(method);
      request.set_allocated_data(&value);

      // Call InvokeService
      Status status = client_stub_->InvokeService(&context, request, &response);

      if (status.ok()) {
        // Unpack the data to string value
        std::string response_data;
        response.SerializeToString(&response_data);
        return response_data;
      }
      return "RPC Error";
    }

    bool SaveMessage(const std::string& message) {
      ClientContext context;

      google::protobuf::Any value;
      value.ParseFromString(message);

      dapr::SaveStateEnvelope request;
      request.set_storename("statestore");
      dapr::StateRequest *stateRequest = request.add_requests();
      stateRequest->set_key("message");
      stateRequest->set_allocated_value(&value);

      google::protobuf::Empty response;
      Status status = client_stub_->SaveState(&context, request, &response);

      return status.ok();
    }

    void StartAppServer() {
      std::string endpoint = dapr_app_endpoint();
      EchoAppServerImpl service;

      grpc::EnableDefaultHealthCheckService(true);
      grpc::reflection::InitProtoReflectionServerBuilderPlugin();

      ServerBuilder builder;
      builder.AddListeningPort(endpoint, grpc::InsecureServerCredentials());
      builder.RegisterService(&service);
      std::unique_ptr<Server> server(builder.BuildAndStart());
      std::cout << "Server listening on " << endpoint << std::endl;
      server->Wait();
    }

  private:
    std::string dapr_app_endpoint() {
      return std::string("localhost:50051");
    }

    std::string dapr_grpc_endpoint() {
      return std::string("localhost:3500");
    }

    std::unique_ptr<Dapr::Stub> client_stub_;
};

} // namepsace dapr_cpp_echo_example


int main(int argc, char** argv) {
  dapr_cpp_echo_example::EchoApp *app = new dapr_cpp_echo_example::EchoApp();
  
  app->StartAppServer();

  std::cout << "Start";

  return 0;
}