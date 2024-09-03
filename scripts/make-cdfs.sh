#!/bin/bash

python_script="./scripts/make-cdf.py"

for raw_file in ./data/stopwatches/*.sw-intervals; do
    if [ -f "$raw_file" ]; then
        echo "Processing $raw_file"
        python3 "$python_script" "$raw_file"
    else
        echo "No raw files found."
    fi
done