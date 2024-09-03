#!/bin/bash

# 1048576

mkdir -p data
mkdir -p data/stopwatches
mkdir -p data/results

./build/bin/dove-generator 1048576

page_chunks=(5 160)
batch_sizes=(32 1)


# Triple nested for loop
for pgs in "${page_chunks[@]}"; do
    for btch in "${batch_sizes[@]}"; do
        ./build/bin/dove-reader data/file.bin 100000 $pgs $btch
        mkdir -p data/results/p$pgs-b$btch
        mv data/stopwatches/* data/results/p$pgs-b$btch/

        sleep 30
    done
done
