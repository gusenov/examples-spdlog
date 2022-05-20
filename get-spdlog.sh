#!/bin/bash

# Usage:
# ./get-gtest.sh 1.8.1

version="$1"

if [ -z "$version" ]; then
    version="1.4.1"
fi

ditrib="v${version}.tar.gz"
ditrib_dir="spdlog-${version}"

curl --silent --location "https://github.com/gabime/spdlog/archive/$ditrib" --output "$ditrib"

if [ ! -f "$ditrib" ]; then
    exit
fi

[ -d "$ditrib_dir" ] && rm -rf "$ditrib_dir"
tar xzf "$ditrib"
rm "$ditrib"

if [ ! -d "$ditrib_dir" ]; then
    exit
fi

find "./$ditrib_dir" -mindepth 1 -maxdepth 1 ! -iname "include" -exec rm -rf {} \;

mv "$ditrib_dir" "spdlog"
