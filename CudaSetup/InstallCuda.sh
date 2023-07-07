#!/bin/bash

#CUDA 11.8, Ubuntu 22.04, x86_64, runfile(local)
DOWNLOAD_DIR="temp"
FILE_URL="https://developer.download.nvidia.com/compute/cuda/11.8.0/local_installers/cuda_11.8.0_520.61.05_linux.run"
FILE_NAME="cuda.run"
TEMP_DIR="temp"
FULL_PATH="$TEMP_DIR/$FILE_NAME"

INSTALLER_PARAMS="--silent --toolkit --samples --override --no-opengl-libs"

if [ ! -f "$FULL_PATH" ]; then
  echo "Downloading $FILE_NAME..."
  mkdir -p "$TEMP_DIR"
  wget "$FILE_URL" -O "$FULL_PATH"
fi

if [ -f "$FULL_PATH" ]; then
  echo "Executing $FILE_NAME with root privileges..."
  sudo sh "$FULL_PATH" $INSTALLER_PARAMS

  # Cleanup: Remove temporary folder
  echo "Cleaning up..."
  rm -rf "$TEMP_DIR"
fi
