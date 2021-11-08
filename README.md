## C++ SDK for Dapr

Alpha quality.

### Prerequisites

> Note: C++ highly depends on the installed dependencies in the system. This project uses VSCode Remote Container environment to build and develop cpp-sdk in a consistent way.

1. Install [Docker CLI](https://docs.docker.com/get-started/)
2. Install [VSCode](https://code.visualstudio.com/download)
3. Install [VSCode Remote - Container extension](https://code.visualstudio.com/docs/remote/containers)

### To refresh .proto files from upstream dapr

1. Rebuild and commit generated API
    ```bash
    export DAPR_TARGET=<runtime_release_tag>
    make refresh_proto_files && make && git add src/dapr/proto/*/v1/*{.cc,.h} dapr/proto/*/v1/*.proto 
    git commit -m "Updating to dapr runtime $DAPR_TARGET"
    ```
2. Submit a PR with the changes

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