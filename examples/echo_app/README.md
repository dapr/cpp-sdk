# Echo app example

This echo app example shows how to use service invocation using gRPC API. You can learn how to create client-side gRPC server and call Dapr gRPC APIs.

## Prerequsites

1. [VSCode environment](../../README.md)

### Build echo app
1. Make sure that you reopen in container on VSCode
2. Open new bash terminal
3. Build echo_app

```
cd examples/echo_app
```

<!-- STEP
name: Build example
-->

```bash
make
```

<!-- END_STEP -->

### Run callee app

1. Open new bash terminal
2. Run callee app

<!-- STEP
name: Run callee
expected_stdout_lines:
  - '== APP == OnInvoke() is called'
  - '== APP == Got the message: hello dapr'
background: true
sleep: 5 
-->

```bash
dapr run --app-id callee --app-protocol grpc --app-port 6000  ./echo_app callee 6000
```

<!-- END_STEP -->

3. Run caller app

<!-- STEP
name: Run caller
expected_stdout_lines:
  - "== APP == Call echo method to callee"
  - "== APP == Received [ack : hello dapr] from callee"
background: true
sleep: 5 
-->

```bash
dapr run --app-id echo_app --app-protocol grpc --app-port 6100 ./echo_app caller 6100 callee
```

<!-- END_STEP -->

4. Check the logs
From callee app:
```
...
== APP == OnInvoke() is called
== APP == Got the message: hello dapr
== APP == OnInvoke() is called
== APP == Got the message: hello dapr
...
```

From caller app:
```
...
== APP == Received [ack : hello dapr] from callee
== APP == Received [ack : hello dapr] from callee
...
```

## Cleanup

<!-- STEP
expected_stdout_lines: 
  - '✅  app stopped successfully: echo_app'
  - '✅  app stopped successfully: callee'
expected_stderr_lines:
name: Shutdown dapr
-->

```bash
dapr stop --app-id echo_app
dapr stop --app-id callee
```

<!-- END_STEP -->

## gRPC Debug

Set the below environment variable to debug gRPC server and client.

```
export GRPC_VERBOSITY=debug 
export GRPC_TRACE=api,-timer_check,-timer
```
