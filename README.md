## C++ SDK for Dapr

Alpha quality.

### Prerequisites

> Note: C++ highly depends on the installed dependencies in the system. This project uses VSCode Remote Container environment to build and develop cpp-sdk in a consistent way.

1. Install [Docker CLI](https://docs.docker.com/get-started/)
2. Install [VSCode](https://code.visualstudio.com/download)
3. Install [VSCode Remote - Container extension](https://code.visualstudio.com/docs/remote/containers)

### Generate gRPC client

1. Copy dapr.proto from https://github.com/dapr/dapr/tree/master/pkg/proto/dapr to [proto](./proto)
2. Copy daprclient.proto from https://github.com/dapr/dapr/tree/master/pkg/proto/daprclient to [proto](./proto)
3. Generate client
    ```bash
    make ./dapr/proto/common/v1/common.pb.cc
    make ./dapr/proto/dapr/v1/dapr.grpc.pb.cc
    make ./dapr/proto/dapr/v1/dapr.pb.cc
    make ./dapr/proto/daprclient/v1/daprclient.grpc.pb.cc
    make ./dapr/proto/daprclient/v1/daprclient.pb.cc
    ```

### Build library

1. Make sure that you enable vscode remote container
2. Build client
    ```bash
    make all
    ```
