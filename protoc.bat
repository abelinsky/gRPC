@echo off
set GRPC_INSTALLED_PATH=/apps/ai/gRPC/vcpkg/installed/x86-windows/tools
set PROTOC=%GRPC_INSTALLED_PATH%/protobuf/protoc.exe
set GRPC_PLUGIN=%GRPC_INSTALLED_PATH%/grpc/grpc_cpp_plugin.exe
set PROTO_FILE=Stackover.proto

%PROTOC% --cpp_out=. %PROTO_FILE%
%PROTOC% --grpc_out=. --plugin=protoc-gen-grpc=%GRPC_PLUGIN% %PROTO_FILE%

echo Files have been generated.

copy.cmd








