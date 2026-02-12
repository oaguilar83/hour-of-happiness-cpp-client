#!/bin/bash

curr_dir=$(pwd)
build_dir=${curr_dir}/../build
target_dir=${build_dir}/src
app_dir=${build_dir}/app

mkdir ${build_dir} && cd ${build_dir}

cmake ..
cmake --build .

mkdir ${app_dir} && cd ${app_dir}
cp ${target_dir}/HoHClient .
ldd HoHClient | awk '/=>/ {print $3}' | xargs -I '{}' cp -v '{}' .
