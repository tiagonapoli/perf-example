#! /bin/bash
g++ -O0 -fno-inline-small-functions -fno-omit-frame-pointer main.cpp 
perf record -F 1000 -g --call-graph dwarf ./a.out
perf script > /tmp/out
./stackcollapse-perf.pl /tmp/out > /tmp/collapsed
./flamegraph.pl /tmp/collapsed > flamegraph.svg