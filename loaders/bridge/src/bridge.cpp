#include "../PACKAGES/grpc/include/grpc++/grpc++.h"
#include "pb/bridge.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using bridgeserver::BridgeServerService;
using bridgeserver::HelloRequest;
using bridgeserver::HelloReply;
using bridgeserver::StreamRequest;
using bridgeserver::StreamReply;

class BridgeServerServiceImpl final : public BridgeServerService::Service {
 Status SayHello(ServerContext* context, const HelloRequest* request,
                  HelloReply* reply) override {
    std::string prefix("Hello ");
    reply->set_message(prefix + request->name());
    return Status::OK;
  }

    Status StreamNumbers(ServerContext* context, const StreamRequest* request,
                        grpc::ServerWriter<StreamReply>* writer) override {
        for (int i = 1; i <= request->limit(); i++) {
        StreamReply reply;
        reply.set_number(i);
        writer->Write(reply);
        }
        return Status::OK;
    }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  BridgeServerServiceImpl service;

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();
  return 0;
}