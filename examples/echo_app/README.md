# Echo app example

## Prerequsites

dapr run --app-id echo_server --protocol grpc --app-port 6000 --redis-host host.docker.internal --placement-host host.docker.internal ./echo_app server 6000

dapr run --app-id echo_app --protocol grpc --app-port 6100 --redis-host host.docker.internal --placement-host host.docker.internal ./echo_app client 6100 echo_server

GRPC_VERBOSITY=debug GRPC_TRACE=api,-timer_check,-timer