#!/usr/bin/env python3

"""
default option specifies the default value
metavar gives a name to the expected value in error and help outputs
"""

import argparse










parser = argparse.ArgumentParser()
parser.add_argument('-b', type=int, required=True, metavar='base', help="defines the base")
parser.add_argument('-e', type=int, default=2, action='append', metavar='exponent', help="defines the exponent")
group = parser.add_mutually_exclusive_group()
group.add_argument('-q', '--quiet', action='store_true', help='no verbosity')
group.add_argument('-v', '--verbose', action='store_true', help='verbose output')
args = parser.parse_args()







val = 1
base = args.b
exps = args.e

for i in range(exps):
    val *= base

# for exp in exps:  # why can't I use append action with int
    # for _ in range(exp):
        # val *= base

if args.quiet:  # I can't use just q here, why?
    print(val)
elif args.verbose:
    if exp:
        print("Power of %s upto %s times is: %s" % (base, exp, val))
    else:
        print("Power of %s upto %s times is: %s" % (base, 2, val))
else:
    print(val)
