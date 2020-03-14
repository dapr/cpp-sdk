## C++ sdk for Dapr

Alpha quality.

### Prerequisites

1. Install [Docker CLI](https://docs.docker.com/get-started/)
2. Install [VSCode](https://code.visualstudio.com/download)
3. Install [VSCode Remote - Container extension](https://code.visualstudio.com/docs/remote/containers)

> Note: this project uses VSCode Remote Container environment to build and develop cpp-sdk

### Update gRPC client

1. Update dapr.proto from https://github.com/dapr/dapr/tree/master/pkg/proto/dapr
2. Update daprclient.proto from https://github.com/dapr/dapr/tree/master/pkg/proto/daprclient
3. Generate client
    ```bash
    make dapr.grpc.pb.cc
    make dapr.pb.cc
    make daprclient.grpc.pb.cc
    make daprclient.pb.cc
    ```

### Build

1. Make sure that you enable vscode remote container
2. Build client
    ```bash
    make all
    ```

