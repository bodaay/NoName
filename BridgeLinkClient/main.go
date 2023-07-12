package main

import (
	"context"
	"fmt"
	"io"
	"log"
	"time"

	pb "bridgelinkclient/pb"

	"google.golang.org/grpc"
)

const (
	address = "localhost:50051" // replace with your server address and port
)

func main() {
	// Set up a connection to the server.
	conn, err := grpc.Dial(address, grpc.WithInsecure(), grpc.WithBlock())
	if err != nil {
		log.Fatalf("did not connect: %v", err)
	}
	defer conn.Close()

	bridgeCoreClient := pb.NewBridgeLinkClient(conn)
	bridgePyTorchClient := pb.NewPyTorchServiceClient(conn)

	GetBridgeServerVersion(bridgeCoreClient)
	GetBridgeServerUpTime(bridgeCoreClient)
	stream, err := bridgeCoreClient.StreamRandomString(context.Background(), &pb.StreamRequest{})
	if err != nil {
		log.Fatalf("Error on get random string: %v", err)
	}
	// Call IsCudaAvailable
	r1, err := bridgePyTorchClient.IsCudaAvailable(context.Background(), &pb.CudaAvailableRequest{})
	if err != nil {
		log.Fatalf("could not check cuda availability: %v", err)
	}
	log.Printf("Cuda Available: %v", r1.GetAvailable())

	// Call GetCudaDeviceCount
	r2, err := bridgePyTorchClient.GetCudaDeviceCount(context.Background(), &pb.CudaDeviceCountRequest{})
	if err != nil {
		log.Fatalf("could not get cuda device count: %v", err)
	}
	log.Printf("Cuda Device Count: %v", r2.GetCount())
	waitc := make(chan struct{})
	go func() {
		defer close(waitc)
		for {
			res, err := stream.Recv()
			if err == io.EOF {
				return
			}
			if err != nil {
				log.Fatalf("Failed to receive a note : %v", err)
			}
			fmt.Printf("Got random string %s\n", res.GetValue())
		}
	}()

	// Check if the stream is working by waiting for a bit.
	time.Sleep(1 * time.Minute)
	stream.CloseSend()
	<-waitc
}

func GetBridgeServerVersion(client pb.BridgeLinkClient) {
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()

	response, err := client.GetServiceLinkVersionNumber(ctx, &pb.ServiceLinkVersionRequest{})
	if err != nil {
		log.Fatalf("ServiceLinkVersionRequest RPC failed: %v", err)
	}
	fmt.Printf("Server replied: %s\n", response.Version)
}
func GetBridgeServerUpTime(client pb.BridgeLinkClient) {
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()

	response, err := client.GetUptime(ctx, &pb.UptimeRequest{})
	if err != nil {
		log.Fatalf("UptimeRequest RPC failed: %v", err)
	}
	fmt.Printf("Server replied: %s\n", response.Uptime)
}

// func GetBridgeServerUpTime(client pb.BridgeLinkClient) {
// 	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
// 	defer cancel()

// 	stream, err := client.GetUptime(ctx, &pb.UptimeRequest{})
// 	if err != nil {
// 		log.Fatalf("StreamNumbers RPC failed: %v", err)
// 	}
// 	for {
// 		response, err := stream.Recv()
// 		if err == io.EOF {
// 			break
// 		}
// 		if err != nil {
// 			log.Fatalf("Failed to receive: %v", err)
// 		}
// 		fmt.Printf("Received: %v\n", response.Number)
// 	}
// }
