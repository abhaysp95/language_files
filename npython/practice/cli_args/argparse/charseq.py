#!/usr/bin/env python3

"""
nargs specifies the number of command-line arguments that should be consumed.
"""

import argparse
import sys

# nargs sets the required number of argument values

parser = argparse.ArgumentParser()
parser.add_argument(
    'chars', type=str, nargs=2, metavar='c', help='starting and ending character'
)
args = parser.parse_args()

try:
    v1 = ord(args.chars[0])
    v2 = ord(args.chars[1])
    for num in range(v1, v2 + 1):
        print(chr(num), end=' ')
    print()  # next line
except TypeError as te:
    print('Error: arguments must be characters')
    parser.print_help()
    sys.exit(1)

if v1 > v2:
    print('first letter must preced the second in alphabet')
    parser.print_help()
    sys.exit(1)
