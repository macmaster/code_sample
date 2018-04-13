import numpy as np 
import pandas as pd 
import seaborn as sns
import time, os, sys

if len(sys.argv) < 3:
  print("usage: chunk.py <input.csv> <output.csv>")
  exit(1)

results_csv = sys.argv[2] 
chunks = pd.read_csv(sys.argv[1], error_bad_lines=False, chunksize=60000)
for chunk in chunks:
  print chunk.head(1)
  chunk['url'] = chunk['url'].apply(str.upper)
  chunk.to_csv (
    results_csv, 
    index=False, 
    encoding='utf-8',
    mode='a',
    header=(not os.path.exists(results_csv)),
  )
