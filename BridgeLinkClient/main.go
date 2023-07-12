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

	client := pb.NewBridgeServerServiceClient(conn)

	SayHello(client)
	StreamNumbers(client)
}

func SayHello(client pb.BridgeServerServiceClient) {
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()

	response, err := client.SayHello(ctx, &pb.HelloRequest{Name: "Khalefa"})
	if err != nil {
		log.Fatalf("SayHello RPC failed: %v", err)
	}
	fmt.Printf("Server replied: %s\n", response.Message)
}

func StreamNumbers(client pb.BridgeServerServiceClient) {
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()

	stream, err := client.StreamNumbers(ctx, &pb.StreamRequest{Limit: 3})
	if err != nil {
		log.Fatalf("StreamNumbers RPC failed: %v", err)
	}
	for {
		response, err := stream.Recv()
		if err == io.EOF {
			break
		}
		if err != nil {
			log.Fatalf("Failed to receive: %v", err)
		}
		fmt.Printf("Received: %v\n", response.Number)
	}
}
