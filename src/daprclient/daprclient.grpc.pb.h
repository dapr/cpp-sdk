// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: daprclient.proto
// Original file comments:
// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
// ------------------------------------------------------------
//
// Dapr 0.5.0 Release
//
#ifndef GRPC_daprclient_2eproto__INCLUDED
#define GRPC_daprclient_2eproto__INCLUDED

#include "daprclient.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/proto_utils.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace daprclient {

// User Code definitions
class DaprClient final {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status OnInvoke(::grpc::ClientContext* context, const ::daprclient::InvokeEnvelope& request, ::google::protobuf::Any* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Any>> AsyncOnInvoke(::grpc::ClientContext* context, const ::daprclient::InvokeEnvelope& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Any>>(AsyncOnInvokeRaw(context, request, cq));
    }
    virtual ::grpc::Status GetTopicSubscriptions(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::daprclient::GetTopicSubscriptionsEnvelope* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::daprclient::GetTopicSubscriptionsEnvelope>> AsyncGetTopicSubscriptions(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::daprclient::GetTopicSubscriptionsEnvelope>>(AsyncGetTopicSubscriptionsRaw(context, request, cq));
    }
    virtual ::grpc::Status GetBindingsSubscriptions(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::daprclient::GetBindingsSubscriptionsEnvelope* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::daprclient::GetBindingsSubscriptionsEnvelope>> AsyncGetBindingsSubscriptions(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::daprclient::GetBindingsSubscriptionsEnvelope>>(AsyncGetBindingsSubscriptionsRaw(context, request, cq));
    }
    virtual ::grpc::Status OnBindingEvent(::grpc::ClientContext* context, const ::daprclient::BindingEventEnvelope& request, ::daprclient::BindingResponseEnvelope* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::daprclient::BindingResponseEnvelope>> AsyncOnBindingEvent(::grpc::ClientContext* context, const ::daprclient::BindingEventEnvelope& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::daprclient::BindingResponseEnvelope>>(AsyncOnBindingEventRaw(context, request, cq));
    }
    virtual ::grpc::Status OnTopicEvent(::grpc::ClientContext* context, const ::daprclient::CloudEventEnvelope& request, ::google::protobuf::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>> AsyncOnTopicEvent(::grpc::ClientContext* context, const ::daprclient::CloudEventEnvelope& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>>(AsyncOnTopicEventRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Any>* AsyncOnInvokeRaw(::grpc::ClientContext* context, const ::daprclient::InvokeEnvelope& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::daprclient::GetTopicSubscriptionsEnvelope>* AsyncGetTopicSubscriptionsRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::daprclient::GetBindingsSubscriptionsEnvelope>* AsyncGetBindingsSubscriptionsRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::daprclient::BindingResponseEnvelope>* AsyncOnBindingEventRaw(::grpc::ClientContext* context, const ::daprclient::BindingEventEnvelope& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::protobuf::Empty>* AsyncOnTopicEventRaw(::grpc::ClientContext* context, const ::daprclient::CloudEventEnvelope& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status OnInvoke(::grpc::ClientContext* context, const ::daprclient::InvokeEnvelope& request, ::google::protobuf::Any* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Any>> AsyncOnInvoke(::grpc::ClientContext* context, const ::daprclient::InvokeEnvelope& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Any>>(AsyncOnInvokeRaw(context, request, cq));
    }
    ::grpc::Status GetTopicSubscriptions(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::daprclient::GetTopicSubscriptionsEnvelope* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::daprclient::GetTopicSubscriptionsEnvelope>> AsyncGetTopicSubscriptions(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::daprclient::GetTopicSubscriptionsEnvelope>>(AsyncGetTopicSubscriptionsRaw(context, request, cq));
    }
    ::grpc::Status GetBindingsSubscriptions(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::daprclient::GetBindingsSubscriptionsEnvelope* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::daprclient::GetBindingsSubscriptionsEnvelope>> AsyncGetBindingsSubscriptions(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::daprclient::GetBindingsSubscriptionsEnvelope>>(AsyncGetBindingsSubscriptionsRaw(context, request, cq));
    }
    ::grpc::Status OnBindingEvent(::grpc::ClientContext* context, const ::daprclient::BindingEventEnvelope& request, ::daprclient::BindingResponseEnvelope* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::daprclient::BindingResponseEnvelope>> AsyncOnBindingEvent(::grpc::ClientContext* context, const ::daprclient::BindingEventEnvelope& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::daprclient::BindingResponseEnvelope>>(AsyncOnBindingEventRaw(context, request, cq));
    }
    ::grpc::Status OnTopicEvent(::grpc::ClientContext* context, const ::daprclient::CloudEventEnvelope& request, ::google::protobuf::Empty* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>> AsyncOnTopicEvent(::grpc::ClientContext* context, const ::daprclient::CloudEventEnvelope& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>>(AsyncOnTopicEventRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::google::protobuf::Any>* AsyncOnInvokeRaw(::grpc::ClientContext* context, const ::daprclient::InvokeEnvelope& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::daprclient::GetTopicSubscriptionsEnvelope>* AsyncGetTopicSubscriptionsRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::daprclient::GetBindingsSubscriptionsEnvelope>* AsyncGetBindingsSubscriptionsRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::daprclient::BindingResponseEnvelope>* AsyncOnBindingEventRaw(::grpc::ClientContext* context, const ::daprclient::BindingEventEnvelope& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* AsyncOnTopicEventRaw(::grpc::ClientContext* context, const ::daprclient::CloudEventEnvelope& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::RpcMethod rpcmethod_OnInvoke_;
    const ::grpc::RpcMethod rpcmethod_GetTopicSubscriptions_;
    const ::grpc::RpcMethod rpcmethod_GetBindingsSubscriptions_;
    const ::grpc::RpcMethod rpcmethod_OnBindingEvent_;
    const ::grpc::RpcMethod rpcmethod_OnTopicEvent_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status OnInvoke(::grpc::ServerContext* context, const ::daprclient::InvokeEnvelope* request, ::google::protobuf::Any* response);
    virtual ::grpc::Status GetTopicSubscriptions(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::daprclient::GetTopicSubscriptionsEnvelope* response);
    virtual ::grpc::Status GetBindingsSubscriptions(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::daprclient::GetBindingsSubscriptionsEnvelope* response);
    virtual ::grpc::Status OnBindingEvent(::grpc::ServerContext* context, const ::daprclient::BindingEventEnvelope* request, ::daprclient::BindingResponseEnvelope* response);
    virtual ::grpc::Status OnTopicEvent(::grpc::ServerContext* context, const ::daprclient::CloudEventEnvelope* request, ::google::protobuf::Empty* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_OnInvoke : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_OnInvoke() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_OnInvoke() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status OnInvoke(::grpc::ServerContext* context, const ::daprclient::InvokeEnvelope* request, ::google::protobuf::Any* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestOnInvoke(::grpc::ServerContext* context, ::daprclient::InvokeEnvelope* request, ::grpc::ServerAsyncResponseWriter< ::google::protobuf::Any>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetTopicSubscriptions : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetTopicSubscriptions() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_GetTopicSubscriptions() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetTopicSubscriptions(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::daprclient::GetTopicSubscriptionsEnvelope* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetTopicSubscriptions(::grpc::ServerContext* context, ::google::protobuf::Empty* request, ::grpc::ServerAsyncResponseWriter< ::daprclient::GetTopicSubscriptionsEnvelope>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetBindingsSubscriptions : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetBindingsSubscriptions() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_GetBindingsSubscriptions() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetBindingsSubscriptions(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::daprclient::GetBindingsSubscriptionsEnvelope* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetBindingsSubscriptions(::grpc::ServerContext* context, ::google::protobuf::Empty* request, ::grpc::ServerAsyncResponseWriter< ::daprclient::GetBindingsSubscriptionsEnvelope>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_OnBindingEvent : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_OnBindingEvent() {
      ::grpc::Service::MarkMethodAsync(3);
    }
    ~WithAsyncMethod_OnBindingEvent() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status OnBindingEvent(::grpc::ServerContext* context, const ::daprclient::BindingEventEnvelope* request, ::daprclient::BindingResponseEnvelope* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestOnBindingEvent(::grpc::ServerContext* context, ::daprclient::BindingEventEnvelope* request, ::grpc::ServerAsyncResponseWriter< ::daprclient::BindingResponseEnvelope>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(3, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_OnTopicEvent : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_OnTopicEvent() {
      ::grpc::Service::MarkMethodAsync(4);
    }
    ~WithAsyncMethod_OnTopicEvent() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status OnTopicEvent(::grpc::ServerContext* context, const ::daprclient::CloudEventEnvelope* request, ::google::protobuf::Empty* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestOnTopicEvent(::grpc::ServerContext* context, ::daprclient::CloudEventEnvelope* request, ::grpc::ServerAsyncResponseWriter< ::google::protobuf::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(4, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_OnInvoke<WithAsyncMethod_GetTopicSubscriptions<WithAsyncMethod_GetBindingsSubscriptions<WithAsyncMethod_OnBindingEvent<WithAsyncMethod_OnTopicEvent<Service > > > > > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_OnInvoke : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_OnInvoke() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_OnInvoke() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status OnInvoke(::grpc::ServerContext* context, const ::daprclient::InvokeEnvelope* request, ::google::protobuf::Any* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetTopicSubscriptions : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetTopicSubscriptions() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_GetTopicSubscriptions() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetTopicSubscriptions(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::daprclient::GetTopicSubscriptionsEnvelope* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetBindingsSubscriptions : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetBindingsSubscriptions() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_GetBindingsSubscriptions() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetBindingsSubscriptions(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::daprclient::GetBindingsSubscriptionsEnvelope* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_OnBindingEvent : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_OnBindingEvent() {
      ::grpc::Service::MarkMethodGeneric(3);
    }
    ~WithGenericMethod_OnBindingEvent() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status OnBindingEvent(::grpc::ServerContext* context, const ::daprclient::BindingEventEnvelope* request, ::daprclient::BindingResponseEnvelope* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_OnTopicEvent : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_OnTopicEvent() {
      ::grpc::Service::MarkMethodGeneric(4);
    }
    ~WithGenericMethod_OnTopicEvent() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status OnTopicEvent(::grpc::ServerContext* context, const ::daprclient::CloudEventEnvelope* request, ::google::protobuf::Empty* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_OnInvoke : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_OnInvoke() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::StreamedUnaryHandler< ::daprclient::InvokeEnvelope, ::google::protobuf::Any>(std::bind(&WithStreamedUnaryMethod_OnInvoke<BaseClass>::StreamedOnInvoke, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_OnInvoke() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status OnInvoke(::grpc::ServerContext* context, const ::daprclient::InvokeEnvelope* request, ::google::protobuf::Any* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedOnInvoke(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::daprclient::InvokeEnvelope,::google::protobuf::Any>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_GetTopicSubscriptions : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_GetTopicSubscriptions() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::StreamedUnaryHandler< ::google::protobuf::Empty, ::daprclient::GetTopicSubscriptionsEnvelope>(std::bind(&WithStreamedUnaryMethod_GetTopicSubscriptions<BaseClass>::StreamedGetTopicSubscriptions, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_GetTopicSubscriptions() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetTopicSubscriptions(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::daprclient::GetTopicSubscriptionsEnvelope* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedGetTopicSubscriptions(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::google::protobuf::Empty,::daprclient::GetTopicSubscriptionsEnvelope>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_GetBindingsSubscriptions : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_GetBindingsSubscriptions() {
      ::grpc::Service::MarkMethodStreamed(2,
        new ::grpc::StreamedUnaryHandler< ::google::protobuf::Empty, ::daprclient::GetBindingsSubscriptionsEnvelope>(std::bind(&WithStreamedUnaryMethod_GetBindingsSubscriptions<BaseClass>::StreamedGetBindingsSubscriptions, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_GetBindingsSubscriptions() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetBindingsSubscriptions(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::daprclient::GetBindingsSubscriptionsEnvelope* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedGetBindingsSubscriptions(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::google::protobuf::Empty,::daprclient::GetBindingsSubscriptionsEnvelope>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_OnBindingEvent : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_OnBindingEvent() {
      ::grpc::Service::MarkMethodStreamed(3,
        new ::grpc::StreamedUnaryHandler< ::daprclient::BindingEventEnvelope, ::daprclient::BindingResponseEnvelope>(std::bind(&WithStreamedUnaryMethod_OnBindingEvent<BaseClass>::StreamedOnBindingEvent, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_OnBindingEvent() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status OnBindingEvent(::grpc::ServerContext* context, const ::daprclient::BindingEventEnvelope* request, ::daprclient::BindingResponseEnvelope* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedOnBindingEvent(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::daprclient::BindingEventEnvelope,::daprclient::BindingResponseEnvelope>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_OnTopicEvent : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_OnTopicEvent() {
      ::grpc::Service::MarkMethodStreamed(4,
        new ::grpc::StreamedUnaryHandler< ::daprclient::CloudEventEnvelope, ::google::protobuf::Empty>(std::bind(&WithStreamedUnaryMethod_OnTopicEvent<BaseClass>::StreamedOnTopicEvent, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_OnTopicEvent() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status OnTopicEvent(::grpc::ServerContext* context, const ::daprclient::CloudEventEnvelope* request, ::google::protobuf::Empty* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedOnTopicEvent(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::daprclient::CloudEventEnvelope,::google::protobuf::Empty>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_OnInvoke<WithStreamedUnaryMethod_GetTopicSubscriptions<WithStreamedUnaryMethod_GetBindingsSubscriptions<WithStreamedUnaryMethod_OnBindingEvent<WithStreamedUnaryMethod_OnTopicEvent<Service > > > > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_OnInvoke<WithStreamedUnaryMethod_GetTopicSubscriptions<WithStreamedUnaryMethod_GetBindingsSubscriptions<WithStreamedUnaryMethod_OnBindingEvent<WithStreamedUnaryMethod_OnTopicEvent<Service > > > > > StreamedService;
};

}  // namespace daprclient


#endif  // GRPC_daprclient_2eproto__INCLUDED
