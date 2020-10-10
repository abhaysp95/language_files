#!usr/bin/env python3

import sys

def checkArg():
    try:
        print(sys.argv[1])
    except IndexError:
        print("provide arg")

checkArg()
