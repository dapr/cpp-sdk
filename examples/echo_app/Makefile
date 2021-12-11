# ------------------------------------------------------------
# Copyright 2021 The Dapr Authors
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#     http://www.apache.org/licenses/LICENSE-2.0
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ------------------------------------------------------------

HOST_SYSTEM = $(shell uname | cut -f 1 -d_)
SYSTEM ?= $(HOST_SYSTEM)
CXX = g++
CPPFLAGS += `pkg-config --cflags protobuf grpc`
CXXFLAGS += -std=c++11 -I ../../src 
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

DAPR_SRC_ROOT = ../../src/dapr/proto

all: echo_app

echo_app: $(DAPR_SRC_ROOT)/common/v1/common.pb.o $(DAPR_SRC_ROOT)/runtime/v1/dapr.pb.o $(DAPR_SRC_ROOT)/runtime/v1/dapr.grpc.pb.o $(DAPR_SRC_ROOT)/runtime/v1/appcallback.pb.o $(DAPR_SRC_ROOT)/runtime/v1/appcallback.grpc.pb.o echo_app_server_impl.o echo_app.o
	$(CXX) $^ $(LDFLAGS) -o $@

clean:
	rm -f *.o echo_app
