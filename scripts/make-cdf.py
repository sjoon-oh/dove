# Sukjoon Oh,
# -- Refined

import argparse
import math
import numpy as np
import pandas as pd

import sys, os

from pathlib import Path

# 
def load_data(filename):
    return pd.read_csv(filename, delimiter='\t', header=None)

#
# 
if __name__ == "__main__":

    print("Single column raw file CDF generator.")

    if len(sys.argv) != 2:
        print(f"Error: argument length {len(sys.argv) - 1}")
        exit()

    scriptname = sys.argv[0]
    filename = sys.argv[1] # First argument should be a filename

    data = load_data(filename)
    data = data[0]

    data_list = data.to_list()
    data_sorted = np.sort(data_list)

    cdf = np.arange(1, len(data_sorted) + 1) / len(data_sorted)

    x_val = data_sorted
    y_val = cdf

    total_len = len(data_sorted)
    
    avg = np.mean(data_sorted)
    val_50 = data_sorted[int(total_len / 2)]
    val_90 = data_sorted[int(total_len * 0.9)]
    val_99 = data_sorted[int(total_len * 0.99)]

    raw_filename = Path(filename).stem
    with open(f"{raw_filename}-summary.csv", "w") as f:
        f.write(f"{avg:.3f}, {val_50:.3f}, {val_90:.3f}, {val_99:.3f}")

    cdf_df = pd.DataFrame(
        {
            'val': x_val,
            'cdf': y_val
        }
    )
    
    cdf_df = cdf_df.groupby('val', as_index=False).max()
    cdf_df = cdf_df.sort_values(by='val')

    # unique, counts = np.unique(data_list, return_counts=True)
    # x_val = unique
    # y_val = counts
    
    csv_path = f"{raw_filename}.csv"
    cdf_df.to_csv(csv_path, index=False, header=False, sep='\t')

    print(f"Exported: {csv_path}")


