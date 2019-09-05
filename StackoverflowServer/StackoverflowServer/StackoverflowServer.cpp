// StackoverflowServer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "Stackover.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;

// Logic and data behind the server's behavior.
class GreeterServiceImpl final : public Greeter::Service {
	Status SayHello(ServerContext* context, const HelloRequest* request,
		HelloReply* reply) override {
		std::string replymsg("Hello " + request->name());
		
		if (request->name() == "ab") {
			replymsg = "Hello, ab, yes, it works!";
		}
		reply->set_message(replymsg);
		return Status::OK;
	}
};

void RunServer() {
	std::string server_address("0.0.0.0:50051");
	GreeterServiceImpl service;

	ServerBuilder builder;
	// Listen on the given address without any authentication mechanism.
	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	// Register "service" as the instance through which we'll communicate with
	// clients. In this case it corresponds to an *synchronous* service.
	builder.RegisterService(&service);
	// Finally assemble the server.
	std::unique_ptr<Server> server(builder.BuildAndStart());
	std::cout << "Server listening on " << server_address << std::endl;

	// Wait for the server to shutdown. Note that some other thread must be
	// responsible for shutting down the server for this call to ever return.
	server->Wait();
}

int main(int argc, char** argv) {
	RunServer();

	return 0;
}