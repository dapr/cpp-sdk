## C++ SDK for Dapr

[![License: Apache 2.0][apache-badge]][apache-url] [![Good First Issues][gfi-badge]][gfi-url] [![Discord][discord-badge]][discord-url] [![YouTube][youtube-badge]][youtube-link] [![X/Twitter][x-badge]][x-link]

[apache-badge]: https://img.shields.io/github/license/dapr/cpp-sdk?style=flat&label=License&logo=github
[apache-url]: https://github.com/dapr/cpp-sdk/blob/master/LICENSE
[gfi-badge]: https://img.shields.io/github/issues-search/dapr/cpp-sdk?query=type%3Aissue%20is%3Aopen%20label%3A%22good%20first%20issue%22&label=Good%20first%20issues&style=flat&logo=github
[gfi-url]: https://github.com/dapr/cpp-sdk/issues?q=is%3Aissue+is%3Aopen+label%3A%22good+first+issue%22
[discord-badge]: https://img.shields.io/discord/778680217417809931?label=Discord&style=flat&logo=discord
[discord-url]: https://bit.ly/dapr-discord
[youtube-badge]: https://img.shields.io/youtube/channel/views/UCtpSQ9BLB_3EXdWAUQYwnRA?style=flat&label=YouTube%20views&logo=youtube
[youtube-link]: https://youtube.com/@daprdev
[x-badge]: https://img.shields.io/twitter/follow/daprdev?logo=x&style=flat
[x-link]: https://twitter.com/daprdev

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
