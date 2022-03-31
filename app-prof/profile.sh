#! /bin/bash
g++ -O0 -fno-inline-small-functions -fno-omit-frame-pointer main.cpp

# -F 1000: 1000Hz
# -g: Gravar os stack traces 
perf record -F 1000 -g --call-graph dwarf ./a.out

# gera o arquivo com os samples da stacks
perf script > /tmp/out

# parseia o arquivo com os samples das stacks para um formato compativel pra gerar o flamegraph
./stackcollapse-perf.pl /tmp/out > /tmp/collapsed

# gera o flamegraph
./flamegraph.pl /tmp/collapsed > flamegraph.svg