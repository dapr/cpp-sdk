// ------------------------------------------------------------------------
// Copyright 2026 The Dapr Authors
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

#include <cassert>
#include <string>

#include <google/protobuf/unknown_field_set.h>

#include "dapr/workflow_termination_reason.h"

using dapr::proto::runtime::v1::GetWorkflowResponse;
using dapr::proto::runtime::v1::TerminateWorkflowRequest;

namespace {

void TestTerminationReasonRoundTripsOnWire() {
  TerminateWorkflowRequest request;
  request.set_instance_id("order-123");
  request.set_workflow_component("dapr");

  const std::string expected = "cancelled by operator";
  assert(dapr::workflow::SetTerminationReason(&request, expected));

  std::string bytes;
  assert(request.SerializeToString(&bytes));

  TerminateWorkflowRequest decoded;
  assert(decoded.ParseFromString(bytes));
  assert(decoded.instance_id() == "order-123");
  assert(decoded.workflow_component() == "dapr");

  const google::protobuf::FieldDescriptor* reason_field =
      decoded.GetDescriptor()->FindFieldByNumber(
          dapr::workflow::kTerminationReasonFieldNumber);
  if (reason_field != nullptr) {
    assert(reason_field->name() == "reason");
    assert(decoded.GetReflection()->HasField(decoded, reason_field));
    assert(decoded.GetReflection()->GetString(decoded, reason_field) == expected);
  } else {
    const google::protobuf::UnknownFieldSet& unknown_fields =
        decoded.GetReflection()->GetUnknownFields(decoded);
    bool found = false;
    for (int i = 0; i < unknown_fields.field_count(); ++i) {
      const google::protobuf::UnknownField& field = unknown_fields.field(i);
      if (field.number() == dapr::workflow::kTerminationReasonFieldNumber &&
          field.type() == google::protobuf::UnknownField::TYPE_LENGTH_DELIMITED &&
          field.length_delimited() == expected) {
        found = true;
      }
    }
    assert(found);
  }
}

void TestSettingReasonReplacesPreviousValue() {
  TerminateWorkflowRequest request;
  assert(dapr::workflow::SetTerminationReason(&request, "first"));
  assert(dapr::workflow::SetTerminationReason(&request, "second"));

  const google::protobuf::FieldDescriptor* reason_field =
      request.GetDescriptor()->FindFieldByNumber(
          dapr::workflow::kTerminationReasonFieldNumber);
  if (reason_field != nullptr) {
    assert(request.GetReflection()->GetString(request, reason_field) == "second");
  } else {
    const google::protobuf::UnknownFieldSet& unknown_fields =
        request.GetReflection()->GetUnknownFields(request);
    int matching_fields = 0;
    for (int i = 0; i < unknown_fields.field_count(); ++i) {
      const google::protobuf::UnknownField& field = unknown_fields.field(i);
      if (field.number() == dapr::workflow::kTerminationReasonFieldNumber) {
        ++matching_fields;
        assert(field.type() == google::protobuf::UnknownField::TYPE_LENGTH_DELIMITED);
        assert(field.length_delimited() == "second");
      }
    }
    assert(matching_fields == 1);
  }
}

void TestEmptyReasonIsPreserved() {
  TerminateWorkflowRequest request;
  assert(dapr::workflow::SetTerminationReason(&request, "first"));
  assert(dapr::workflow::SetTerminationReason(&request, ""));

  const google::protobuf::FieldDescriptor* reason_field =
      request.GetDescriptor()->FindFieldByNumber(
          dapr::workflow::kTerminationReasonFieldNumber);
  if (reason_field != nullptr) {
    assert(request.GetReflection()->HasField(request, reason_field));
    assert(request.GetReflection()->GetString(request, reason_field).empty());
  } else {
    const google::protobuf::UnknownFieldSet& unknown_fields =
        request.GetReflection()->GetUnknownFields(request);
    int matching_fields = 0;
    for (int i = 0; i < unknown_fields.field_count(); ++i) {
      const google::protobuf::UnknownField& field = unknown_fields.field(i);
      if (field.number() == dapr::workflow::kTerminationReasonFieldNumber) {
        ++matching_fields;
        assert(field.type() == google::protobuf::UnknownField::TYPE_LENGTH_DELIMITED);
        assert(field.length_delimited().empty());
      }
    }
    assert(matching_fields == 1);
  }
}


void TestUnspecifiedReasonRemainsOmitted() {
  TerminateWorkflowRequest request;
  const google::protobuf::FieldDescriptor* reason_field =
      request.GetDescriptor()->FindFieldByNumber(
          dapr::workflow::kTerminationReasonFieldNumber);
  if (reason_field != nullptr) {
    assert(!request.GetReflection()->HasField(request, reason_field));
  } else {
    const google::protobuf::UnknownFieldSet& unknown_fields =
        request.GetReflection()->GetUnknownFields(request);
    for (int i = 0; i < unknown_fields.field_count(); ++i) {
      assert(unknown_fields.field(i).number() !=
             dapr::workflow::kTerminationReasonFieldNumber);
    }
  }
}

void TestReadsReasonFromWorkflowMetadata() {
  GetWorkflowResponse response;
  (*response.mutable_properties())[dapr::workflow::kTerminationReasonProperty] =
      "cancelled by operator";

  std::string reason;
  assert(dapr::workflow::TryGetTerminationReason(response, &reason));
  assert(reason == "cancelled by operator");

  GetWorkflowResponse empty_reason;
  (*empty_reason.mutable_properties())[dapr::workflow::kTerminationReasonProperty] = "";
  assert(dapr::workflow::TryGetTerminationReason(empty_reason, &reason));
  assert(reason.empty());

  GetWorkflowResponse without_reason;
  assert(!dapr::workflow::TryGetTerminationReason(without_reason, &reason));
  assert(reason.empty());
  assert(!dapr::workflow::TryGetTerminationReason(response, nullptr));
}

}  // namespace

int main() {
  TestTerminationReasonRoundTripsOnWire();
  TestSettingReasonReplacesPreviousValue();
  TestEmptyReasonIsPreserved();
  TestUnspecifiedReasonRemainsOmitted();
  TestReadsReasonFromWorkflowMetadata();
  return 0;
}
