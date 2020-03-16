HOST_SYSTEM = $(shell uname | cut -f 1 -d_)
SYSTEM ?= $(HOST_SYSTEM)
CXX = g++
CPPFLAGS += `pkg-config --cflags protobuf grpc`
CXXFLAGS += -std=c++11
ifeq ($(SYSTEM),Darwin)
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
           -pthread\
           -lgrpc++_reflection\
           -ldl
else
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
           -pthread\
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
           -ldl
endif

DAPR_SRC_ROOT = ../../src

all: echo_app

echo_app: $(DAPR_SRC_ROOT)/dapr/dapr.pb.o $(DAPR_SRC_ROOT)/dapr/dapr.grpc.pb.o $(DAPR_SRC_ROOT)/daprclient/daprclient.pb.o $(DAPR_SRC_ROOT)/daprclient/daprclient.grpc.pb.o echo_app_server_impl.o echo_app.o
	$(CXX) $^ $(LDFLAGS) -o $@

clean:
	rm -f *.o echo_app
