// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
// ------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

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
    EchoApp(std::string dapr_grpc_port, std::string app_port)
      : dapr_grpc_port_(dapr_grpc_port), app_port_(app_port) {}

    void ConnectToDapr() {
      // Connect to dapr grpc server.
      std::cout << "Connecting to " << dapr_grpc_endpoint() << "..." << std::endl;
      client_stub_ = Dapr::NewStub(grpc::CreateChannel(dapr_grpc_endpoint(), grpc::InsecureChannelCredentials()));
    }

    std::string CallMethod(
      const std::string app_id, const std::string method,
      const std::string message) {
      ClientContext context;
      dapr::InvokeServiceEnvelope request;
      dapr::InvokeServiceResponseEnvelope response;

      // Construct service invocation request
      request.set_id(app_id);
      request.set_method(method);
      request.mutable_data()->mutable_value()->assign(message);

      // Call InvokeService
      Status status = client_stub_->InvokeService(&context, request, &response);

      if (status.ok()) {
        return response.data().value();
      }

      return "RPC Error : " + status.error_message() + ", " + status.error_details();
    }

    bool SaveMessage(const std::string message) {
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
      std::string endpoint = echo_app_endpoint();
      service_ = std::shared_ptr<EchoAppServerImpl>(new EchoAppServerImpl());

      grpc::EnableDefaultHealthCheckService(true);
      grpc::reflection::InitProtoReflectionServerBuilderPlugin();

      ServerBuilder builder;
      builder.AddListeningPort(endpoint, grpc::InsecureServerCredentials());
      builder.RegisterService(service_.get());
      
      // Start synchronous gRPC server.
      app_server_ = builder.BuildAndStart();
      std::cout << "Server listening on " << endpoint << std::endl;
    }

    void WaitUntilServerIsDown() {
      app_server_->Wait();
    }

  private:
    std::string echo_app_endpoint() {
      return std::string("127.0.0.1:") + app_port_;
    }

    std::string dapr_grpc_endpoint() {
      return std::string("127.0.0.1:") + dapr_grpc_port_;
    }

    std::string app_port_;
    std::string dapr_grpc_port_;
    std::unique_ptr<Dapr::Stub> client_stub_;
    std::unique_ptr<Server> app_server_;
    std::shared_ptr<EchoAppServerImpl> service_;
};

} // namepsace dapr_cpp_echo_example

std::string GetEnvironmentVariable(const std::string& var) {
  const char* val = std::getenv(var.c_str());
  return (val == nullptr) ? "": val;
}

int main(int argc, char** argv) {
  if (argc < 3) {
    std::cout << "echo_app <mode> <app_port> <callee>" << std::endl;
    return 0;
  }

  std::string grpc_port = GetEnvironmentVariable("DAPR_GRPC_PORT");
  std::string mode = std::string(argv[1]);
  std::string app_port = std::string(argv[2]);
  std::string callee;

  if (mode == "client") {
    if (argc < 4) {
      std::cout << "<callee> is required" << std::endl;
      return 0;
    }
    callee = std::string(argv[3]);
  }
  
  if (grpc_port == "") grpc_port = "50001";

  std::cout 
    << "Start echo app (" << mode << ") - callee: " << callee
    << ", Dapr gRPC Port: " << grpc_port << ", Echo App Port: " << app_port << std::endl;

  std::unique_ptr<dapr_cpp_echo_example::EchoApp> app(new dapr_cpp_echo_example::EchoApp(grpc_port, app_port));

  // Start App Server
  app->StartAppServer();

  // TODO: run the client as a separate thread.
  if (mode == "client") {
    app->ConnectToDapr();
    std::cout << "Call echo method to " << callee << std::endl;

    while (true) {
      std::string response = app->CallMethod(callee, "echo", "hello dapr");
      std::cout << "Received [" << response << "] from " << callee << std::endl;
      // sleep 5 second
      std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
  }

  // Wait until server is down
  app->WaitUntilServerIsDown();

  return 0;
}