cmake_minimum_required(VERSION 2.8)

set(APPNAME echo_app)
set(ROOT_DIR ../../src)

project(${APPNAME})

set(ENV{PKG_CONFIG_PATH} /usr/lib/pkgconfig)
find_package(PkgConfig)
pkg_search_module(PROTOBUF REQUIRED protobuf)
pkg_search_module(GRPC REQUIRED grpc)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -g -W")

include_directories(${ROOT_DIR})

# add current directory to DIRSRCS
aux_source_directory(. DIRSRCS)
aux_source_directory(${ROOT_DIR}/dapr/proto/common/v1 PROTO_COMMON_LIST)
aux_source_directory(${ROOT_DIR}/dapr/proto/runtime/v1 PROTO_RUNTIME_LIST)

# generate application
add_executable(${APPNAME}
    ${DIRSRCS}
    ${PROTO_COMMON_LIST}
    ${PROTO_RUNTIME_LIST}
    )

target_link_libraries(${APPNAME}
    protobuf
    grpc++
    grpc++_reflection
    )