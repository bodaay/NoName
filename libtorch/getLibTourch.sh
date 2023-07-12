#!/bin/bash

# PyTorch 2.01,Linux,LibTorch,c++/java,CUDA 11.8,cxx11 ABI
libtorchURL="https://download.pytorch.org/libtorch/cu118/libtorch-cxx11-abi-shared-with-deps-2.0.1%2Bcu118.zip"
extractPath="src"

# Below Written by ChatGPT 3.5, this function will check if unzip available, check if folder exists before, download the zip file and make sure the root folder of it 'libtorch' is removed and all of its content placed in our folder
download_and_extract() {
    local url="$1"
    local folder="$2"

    # Check if unzip is available
    if ! command -v unzip >/dev/null 2>&1; then
        echo "The 'unzip' command is not available."
        read -p "Do you want to install unzip? (y/n): " answer
        if [[ "$answer" =~ ^[Yy]$ ]]; then
            # Install unzip
            sudo apt-get install unzip
        else
            echo "Aborting the script."
            exit 1
        fi
    fi

    # Check if folder exists or create it
    if [ ! -d "$folder" ]; then
        mkdir -p "$folder"
    else
        read -p "The folder '$folder' already exists. Do you want to redownload and overwrite? (y/n): " answer
        if [[ "$answer" =~ ^[Yy]$ ]]; then
            # Remove the existing folder
            rm -r "$folder"
            mkdir -p "$folder"
        else
            echo "Aborting the script."
            exit 1
        fi
    fi

     # Download the zip file
    echo "Downloading $url..."
    wget "$url" -O temp.zip

    # Extract to the specified folder
    echo "Extracting to $folder..."
    unzip -q temp.zip -d temp_folder
    mv temp_folder/*/* "$folder"

    # Cleanup: remove the temporary folder and zip file
    rm -r temp_folder temp.zip

    echo "Extraction complete."
}


download_and_extract "$libtorchURL" "$extractPath"
