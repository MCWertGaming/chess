#!/bin/bash
set -ex

# compile function
compile()
{
    cmake -DCMAKE_INSTALL_PREFIX=`pwd`/inst .
    cmake --build . --config Release
    cmake --build . --config Debug
}
# run programms function
run_programs()
{
    # ./build/chess_fronts/
    # ./build/chess_src/
    ./build/tests/testing-target
}

# test with gcc
export CC=/usr/bin/gcc
export CXX=/usr/bin/g++
compile
run_programs

# cleanup cmake
git reset --hard

# test with clang
export CC=/usr/bin/clang
export CXX=/usr/bin/clang++
compile
run_programs