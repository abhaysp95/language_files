#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-07
Description: sample foo file
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-04-07
"""


# suppose this is foo.py

import math
print("after import")

print("before functiona")


def functiona():
    '''just a functiona'''
    print("Function A")


print("before functionb")


def functionb():
    '''just a functionb'''
    print("Function B {}".format(math.sqrt(729)))


print("before __name__ guard")

if __name__ == '__main__':
    functiona()
    functionb()
print("after __name__ guard")
