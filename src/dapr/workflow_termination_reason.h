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

#ifndef DAPR_WORKFLOW_TERMINATION_REASON_H
#define DAPR_WORKFLOW_TERMINATION_REASON_H

#include <string>

#include <google/protobuf/descriptor.h>
#include <google/protobuf/unknown_field_set.h>

#include "dapr/proto/runtime/v1/dapr.pb.h"

namespace dapr {
namespace workflow {

static const int kTerminationReasonFieldNumber = 4;

static const char kTerminationReasonProperty[] = "dapr.workflow.termination_reason";

inline bool SetTerminationReason(
    dapr::proto::runtime::v1::TerminateWorkflowRequest* request,
    const std::string& reason) {
  if (request == nullptr) {
    return false;
  }

  const google::protobuf::Descriptor* descriptor = request->GetDescriptor();
  const google::protobuf::FieldDescriptor* field =
      descriptor->FindFieldByNumber(kTerminationReasonFieldNumber);

  if (field != nullptr) {
    if (field->name() != "reason" ||
        field->cpp_type() != google::protobuf::FieldDescriptor::CPPTYPE_STRING ||
        field->is_repeated()) {
      return false;
    }

    const google::protobuf::Reflection* reflection = request->GetReflection();
    reflection->SetString(request, field, reason);
    return true;
  }

  google::protobuf::UnknownFieldSet* unknown_fields =
      request->GetReflection()->MutableUnknownFields(request);
  unknown_fields->DeleteByNumber(kTerminationReasonFieldNumber);
  unknown_fields->AddLengthDelimited(kTerminationReasonFieldNumber, reason);

  return true;
}

inline bool TryGetTerminationReason(
    const dapr::proto::runtime::v1::GetWorkflowResponse& response,
    std::string* reason) {
  if (reason == nullptr) {
    return false;
  }

  const auto& properties = response.properties();
  const auto found = properties.find(kTerminationReasonProperty);
  if (found == properties.end()) {
    reason->clear();
    return false;
  }

  *reason = found->second;
  return true;
}

}
}

#endif
