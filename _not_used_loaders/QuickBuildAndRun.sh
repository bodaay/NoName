#!/bin/bash

go build -o out/linux/amd64/NoName .
mkdir -p out/linux/amd64/lib/
cp lib/* out/linux/amd64/lib/
./out/linux/amd64/NoName