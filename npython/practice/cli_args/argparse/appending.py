#!/usr/bin/env python3

import argparse

parser = argparse.ArgumentParser()

parser.add_argument('-n', '--name', dest='names', type=int, action='append', help='provide names to greet')
args = parser.parse_args()

names = args.names

try:
    for name in names:
        print(f"Name: {name}")
except TypeError:
    print("Provide argument and its value")
