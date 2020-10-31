#!/usr/bin/env python3

"""
the type argument determines the argument type
"""

import argparse
import random

parser = argparse.ArgumentParser()
parser.add_argument('-n', type=int, required=True, help='define the number of random integers')
args = parser.parse_args()

n = args.n  # you can use 'dest' to give argument name

for i in range(n):
    print(random.randint(-100, 100))
