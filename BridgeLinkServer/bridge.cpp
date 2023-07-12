#include <chrono>
#include <thread>
#include <random>
#include <string>
#include <grpcpp/grpcpp.h>
#include "pb/bridgelink.grpc.pb.h" // Generated from your protos

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerWriter;
using bridgelink::BridgeLink;
using bridgelink::ServiceLinkVersionRequest;
using bridgelink::ServiceLinkVersionResponse;
using bridgelink::UptimeRequest;
using bridgelink::UptimeResponse;
using bridgelink::StreamRequest;
using bridgelink::StreamResponse;

auto start_time = std::chrono::system_clock::now();

class BridgeLinkServiceImpl final : public BridgeLink::Service {
    Status GetServiceLinkVersionNumber(ServerContext* context, const ServiceLinkVersionRequest* request, 
                                       ServiceLinkVersionResponse* reply) override {
        reply->set_version("1.0.0"); // Hardcoded version number
        return Status::OK;
    }

    Status GetUptime(ServerContext* context, const UptimeRequest* request, 
                     UptimeResponse* reply) override {
        auto end_time = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end_time-start_time;

        reply->set_uptime(std::to_string(elapsed_seconds.count()) + " seconds"); 
        return Status::OK;
    }

    Status StreamRandomString(ServerContext* context, const StreamRequest* request,
                              ServerWriter<StreamResponse>* writer) override {
        std::string chars(
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "1234567890");
        std::random_device rd;
        std::mt19937 generator(rd());

        for (int i = 0; i < 10; i++) {
            std::shuffle(chars.begin(), chars.end(), generator);
            StreamResponse response;
            response.set_value(chars);
            writer->Write(response);
            std::this_thread::sleep_for(std::chrono::seconds(1)); // pause for a second
        }
        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    BridgeLinkServiceImpl service;

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
