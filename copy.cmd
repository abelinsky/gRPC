@echo off
copy Stackover.pb.cc .\StackoverflowClient\StackoverflowClient\Stackover.pb.cc /y
copy Stackover.pb.h .\StackoverflowClient\StackoverflowClient\Stackover.pb.h /y
copy Stackover.grpc.pb.cc .\StackoverflowClient\StackoverflowClient\Stackover.grpc.pb.cc /y
copy Stackover.grpc.pb.h .\StackoverflowClient\StackoverflowClient\Stackover.grpc.pb.h /y

copy Stackover.pb.cc .\StackoverflowServer\StackoverflowServer\Stackover.pb.cc /y
copy Stackover.pb.h .\StackoverflowServer\StackoverflowServer\Stackover.pb.h /y
copy Stackover.grpc.pb.cc .\StackoverflowServer\StackoverflowServer\Stackover.grpc.pb.cc /y
copy Stackover.grpc.pb.h .\StackoverflowServer\StackoverflowServer\Stackover.grpc.pb.h /y