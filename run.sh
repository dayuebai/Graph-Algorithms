#! /bin/bash

echo Start compiling...
g++ -std=c++14 main.cpp -o proj3
echo Finish compiling successfully.

echo Start running...
if [[ "$OSTYPE" == "linux-gnu" ]]; then
    echo System OS: Linux-GNU
    valgrind ./proj3
else
    echo Other system OS
    ./proj3
fi
rm ./proj3
echo Finish running successfully.