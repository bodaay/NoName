#!/bin/bash

# Written by ChatGPT 3.5
                                                                                                                                
packages=("build-essential" "autoconf" "libtool" "pkg-config" "libgrpc++-dev")                                                               
                                                                                                                                
missing_packages=()                                                                                                          
                                                                                                                                
for package in "${packages[@]}"; do                                                                                          
    if ! dpkg -s "$package" >/dev/null 2>&1; then                                                                            
        missing_packages+=("$package")                                                                                       
    fi                                                                                                                       
done                                                                                                                         
                                                                                                                                
if [ ${#missing_packages[@]} -gt 0 ]; then                                                                                   
    echo "The following packages are missing: ${missing_packages[*]}"                                                        
    read -p "Do you want to install them? (y/n): " choice                                                                    
    if [ "$choice" == "y" ]; then                                                                                            
        sudo apt-get install "${missing_packages[@]}"                                                                        
    fi                                                                                                                       
else                                                                                                                         
    echo "All required packages are already installed."                                                                      
fi   


repo="https://github.com/grpc/grpc"
git_clone_or_pull() {
    local repo_url="$1"
    local folder="$2"

    if [ ! -d "$folder" ]; then
        # Folder doesn't exist, perform git clone
        git clone --recurse-submodules -b v1.56.0 --depth 1 --shallow-submodules  "$repo_url" "$folder"
    else
        # Folder exists, perform git pull
        cd "$folder"
        git pull
    fi
}


git_clone_or_pull "$repo" repo
