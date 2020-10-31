#!/usr/bin/env python3

import argparse
from pathlib import Path


# pathlib module can be used as an alternative for os, os.path, glob and
# can also read and write files

parser = argparse.ArgumentParser()
parser.add_argument('f', type=str, help='file name')
parser.add_argument('n', type=int, help='show n lines from the top')
# I think for positional argument, dest option is not required
args = parser.parse_args()


filename = args.f
try:
    lines = Path(filename).read_text().splitlines()

    for line in lines[:args.n]:
        print(line)
except FileNotFoundError:
    print('Provided filename doesn\'t exist in path')
