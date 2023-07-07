#!/bin/bash

# Written by ChatGPT 3.5

repo="https://github.com/PanQiWei/AutoGPTQ"
git_clone_or_pull() {
    local repo_url="$1"
    local folder="$2"

    if [ ! -d "$folder" ]; then
        # Folder doesn't exist, perform git clone
        git clone "$repo_url" "$folder"
    else
        # Folder exists, perform git pull
        cd "$folder"
        git pull
    fi
}


git_clone_or_pull "$repo" repo

echo "copy the files from 'repo'/autogptq_cuda/ to 'src', and modify the code based on what you need"