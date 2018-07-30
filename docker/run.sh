#!/usr/bin/env bash
echo "System:   `uname`"
echo "Compiler: `g++ --version`"
rm -rf build
mkdir build
cd build
files=`ls ../*.cpp`
for file in $files
do
    exe=`basename ${file} .cpp`
    echo "Compiling $exe"
    c++ $file -std=c++11 -I../../single_include -o $exe
done
echo "Done."


