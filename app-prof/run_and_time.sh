#! /bin/bash
g++ -O0 -fno-inline-small-functions -fno-omit-frame-pointer main.cpp
time ./a.out