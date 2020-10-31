#!/usr/bin/env python3

import datetime
import argparse

parser = argparse.ArgumentParser()  # can provide description for args here
parser.add_argument('-n', dest='now', action='store_true', help='shows now')
args = parser.parse_args()

if args.now:
    now = datetime.datetime.now()
    print(f"Now: {now}")
