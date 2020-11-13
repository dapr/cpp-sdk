# ------------------------------------------------------------
# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.
# ------------------------------------------------------------

CXX = g++
PROTOC = protoc
GRPC_CPP_PLUGIN = grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH ?= `which $(GRPC_CPP_PLUGIN)`

OBJ_FILES = src/dapr/proto/common/v1/common.pb.o src/dapr/proto/runtime/v1/dapr.pb.o src/dapr/proto/runtime/v1/dapr.grpc.pb.o src/dapr/proto/runtime/v1/appcallback.pb.o src/dapr/proto/runtime/v1/appcallback.grpc.pb.o

PROTO_FILES = dapr/proto/runtime/v1/dapr.proto dapr/proto/runtime/v1/appcallback.proto dapr/proto/common/v1/common.proto

PROTOS_PATH = .

DAPR_TARGET ?= master

vpath %.proto $(PROTOS_PATH)

all: system-check libdapr.so

libdapr.so : $(OBJ_FILES)
	-mkdir -p ./out
	$(CXX) -shared -Wl,-soname,libdapr.so.0 -o ./out/libdapr.0.2.0.so ./src/dapr/proto/runtime/v1/*.o ./src/dapr/proto/common/v1/*.o

%.o: %.cc
	$(CXX) -c -fPIC -I./src $< -o $@

.PRECIOUS: src/%.grpc.pb.cc
src/%.grpc.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --grpc_out=./src/ --plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN_PATH) $<

.PRECIOUS: src/%.pb.cc
src/%.pb.cc: %.proto
	mkdir -p ./src
	$(PROTOC) -I $(PROTOS_PATH) --cpp_out=./src/ $<

clean:
	rm -f ./src/dapr/proto/common/v1/*.o ./src/dapr/proto/runtime/v1/*.o
	rm -rf ./out

refresh_proto_files:
	for file in $(PROTO_FILES); do \
		curl -o $$file https://raw.githubusercontent.com/dapr/dapr/$(DAPR_TARGET)/$$file; \
	done


# The following is to test your system and ensure a smoother experience.
# They are by no means necessary to actually compile a grpc-enabled software.

PROTOC_CMD = which $(PROTOC)
PROTOC_CHECK_CMD = $(PROTOC) --version | grep -q libprotoc.3
PLUGIN_CHECK_CMD = which $(GRPC_CPP_PLUGIN)
HAS_PROTOC = $(shell $(PROTOC_CMD) > /dev/null && echo true || echo false)
ifeq ($(HAS_PROTOC),true)
HAS_VALID_PROTOC = $(shell $(PROTOC_CHECK_CMD) 2> /dev/null && echo true || echo false)
endif
HAS_PLUGIN = $(shell $(PLUGIN_CHECK_CMD) > /dev/null && echo true || echo false)

SYSTEM_OK = false
ifeq ($(HAS_VALID_PROTOC),true)
ifeq ($(HAS_PLUGIN),true)
SYSTEM_OK = true
endif
endif

system-check:
ifneq ($(HAS_VALID_PROTOC),true)
	@echo " DEPENDENCY ERROR"
	@echo
	@echo "You don't have protoc 3.0.0 installed in your path."
	@echo "Please install Google protocol buffers 3.0.0 and its compiler."
	@echo "You can find it here:"
	@echo
	@echo "   https://github.com/google/protobuf/releases/tag/v3.0.0"
	@echo
	@echo "Here is what I get when trying to evaluate your version of protoc:"
	@echo
	-$(PROTOC) --version
	@echo
	@echo
endif
ifneq ($(HAS_PLUGIN),true)
	@echo " DEPENDENCY ERROR"
	@echo
	@echo "You don't have the grpc c++ protobuf plugin installed in your path."
	@echo "Please install grpc. You can find it here:"
	@echo
	@echo "   https://github.com/grpc/grpc"
	@echo
	@echo "Here is what I get when trying to detect if you have the plugin:"
	@echo
	-which $(GRPC_CPP_PLUGIN)
	@echo
	@echo
endif
ifneq ($(SYSTEM_OK),true)
	@false
endif
