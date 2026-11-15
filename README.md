## C++ SDK for Dapr

Alpha quality.

### Prerequisites

> Note: C++ highly depends on the installed dependencies in the system. This project uses VSCode Remote Container environment to build and develop cpp-sdk in a consistent way.

1. Install [Docker CLI](https://docs.docker.com/get-started/)
2. Install [VSCode](https://code.visualstudio.com/download)
3. Install [VSCode Remote - Container extension](https://code.visualstudio.com/docs/remote/containers)

Alternatively, you can build the image yourself, based on the Dockerfile in the repository:
```bash
docker build -t cppsdk .
```

Then you can access the container's shell and execute commands in it:
```bash
docker run -it -v $(pwd):/sdk cppsdk /bin/bash
```

### To refresh .proto files from upstream dapr

1. Rebuild and commit generated API
    ```bash
    export DAPR_TARGET=<runtime_release_tag>
    make refresh_proto_files && make && git add src/dapr/proto/*/v1/*{.cc,.h} dapr/proto/*/v1/*.proto 
    git commit -m "Updating to dapr runtime $DAPR_TARGET"
    ```
2. Submit a PR with the changes

### Terminate a workflow with a reason

The generated gRPC client exposes the workflow RPCs. Include
`dapr/workflow_termination_reason.h` to set the optional reason and read it
back from the workflow metadata properties.

```cpp
#include <grpcpp/grpcpp.h>
#include <google/protobuf/empty.pb.h>

#include "dapr/proto/runtime/v1/dapr.grpc.pb.h"
#include "dapr/workflow_termination_reason.h"

using dapr::proto::runtime::v1::Dapr;
using dapr::proto::runtime::v1::GetWorkflowRequest;
using dapr::proto::runtime::v1::GetWorkflowResponse;
using dapr::proto::runtime::v1::TerminateWorkflowRequest;

// Connect to the Dapr sidecar's gRPC endpoint.
auto channel = grpc::CreateChannel(
    "127.0.0.1:50001",
    grpc::InsecureChannelCredentials());
auto client = Dapr::NewStub(channel);

// Terminate the workflow. The reason is separate from workflow output.
TerminateWorkflowRequest terminate;
terminate.set_workflow_component("dapr");
terminate.set_instance_id("order-123");
dapr::workflow::SetTerminationReason(
    &terminate,
    "cancelled by operator");

grpc::ClientContext terminate_context;
google::protobuf::Empty terminate_response;
grpc::Status status = client->TerminateWorkflowBeta1(
    &terminate_context,
    terminate,
    &terminate_response);
if (!status.ok()) {
    // Handle the gRPC error.
}

// Read the workflow metadata after termination.
GetWorkflowRequest get;
get.set_workflow_component("dapr");
get.set_instance_id("order-123");

grpc::ClientContext get_context;
GetWorkflowResponse workflow;
status = client->GetWorkflowBeta1(&get_context, get, &workflow);
if (status.ok()) {
    std::string reason;
    if (dapr::workflow::TryGetTerminationReason(workflow, &reason)) {
        // reason == "cancelled by operator"
    }
}
```

The helper writes field 4 of `TerminateWorkflowRequest`, matching the runtime
wire contract. It also supports the older generated bindings currently checked
into this repository by encoding field 4 as an unknown protobuf field. A null
request is rejected; an empty reason clears the field and is treated as omitted.

The runtime exposes the value in
`GetWorkflowResponse.properties["dapr.workflow.termination_reason"]`.
The property is absent when no reason was recorded or when the connected runtime
does not support termination reasons.

After changing a protobuf definition, regenerate the C++ bindings and build:

```bash
make regen_proto_files
make all
make test
```

The feature requires a Dapr runtime that includes workflow termination-reason
support. The upstream runtime HTTP handler still needs to propagate the HTTP
`reason` query parameter; this C++ example uses gRPC.

### Build library

1. Make sure that you enable vscode remote container
2. Build client
    ```bash
    make all
    ```

### Run the example validation

1. Make sure that you enable vscode remote container
2. Run the example validation
    ```bash
    cd examples/echo_app/ && mm.py README.md && echo SUCCESS
    ```