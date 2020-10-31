#!/usr/bin/env python3

"""
This program calculates the volume of a cylinder
"""

import math
import argparse

# create parse(container to hold argument)
parser = argparse.ArgumentParser(
    description='Calculate volume of cylinder')

# make code behave like, when user doesn't provide positional arg, make optional arg mendatory

# giving positional arguments(to test optional one, comment this one out)
# parser.add_argument('radius', type=int, help='Radius of Cylinder')
# parser.add_argument('height', type=int, help='Height of Cylinder')

# let's try optional arguments
parser.add_argument( '-rd', '--radius',
                    type=int, metavar='', required=True, help='Radius of Cylinder')
parser.add_argument('-ht', '--height',
                    type=int, metavar='', required=True, help='Height of Cylinder')
# use metavar to clean up the help

# when it's optional argument if you don't provide the args(value) it'll give
# NoneType to program, to resolve this issue, use required



# mutually exclusive arguments
group = parser.add_mutually_exclusive_group()
group.add_argument('-q', '--quiet', action='store_true', help='print with no extra output')
group.add_argument('-v', '--verbose', action='store_true', help='print with extra details')
# action set to store_true will store the argument as True, if present
args = parser.parse_args()


def volume(radius, height):
    """calc volume of cylinder"""
    return math.pi * math.pow(radius, 2) * height


# if __name__ == "__main__":
    # print("%.3f" % volume(args.radius, args.height))



# change made after adding mutually_exclusive_group
if __name__ == "__main__":
    vol = volume(args.radius, args.height)
    if args.quiet:
        print("%.3f" % vol)
    elif args.verbose:
        print("Volume of a cylinder with radius %s and height %s is %.3f" %
              (args.radius, args.height, vol))
    else:
        print("Volume of cylinder is %.3f" % vol)


# mutually_exclusive_group_args works with both optional and postional args(as tested above)
# there's also something called condtional args(check for it)
