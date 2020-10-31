#!/usr/bin/env python3

"""
variable number of args can be set with * character
"""

import argparse

parser = argparse.ArgumentParser()
parser.add_argument('num', type=int, nargs='*', metavar='n')
args = parser.parse_args()

print(f"The sum of values is {sum(args.num)}")
