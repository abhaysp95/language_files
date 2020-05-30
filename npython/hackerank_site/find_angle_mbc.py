#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
get the angle MBC(downside angle of arm matching the mid point of hypotaneous)
"""

# -*- coding: utf-8 -*-
# (default in python3)
import math


def main():
    '''inside main function'''
    len_ab = int(input())
    len_bc = int(input())

    hypo = math.hypot(len_ab, len_bc)
    deg_abc = math.degrees(math.asin(len_ab/hypo))
    print(deg_abc)
    len_mc = hypo / 2

    # with cosine rule
    len_bm = math.pow(len_mc, 2) + math.pow(len_bc, 2)
    len_bm -= 2 * len_mc * len_bc * math.cos(math.radians(deg_abc))
    len_bm = math.sqrt(len_bm)
    print(len_bm)

    # with sine rule
    got_mdc = (len_mc / len_bm) * math.sin(math.radians(deg_abc))
    deg_mdc = math.degrees(math.asin(got_mdc))

    # print("{:.2f}".format(deg_mdc))
    # have to round acc. to ques
    degree_sign = u"\N{DEGREE SIGN}"
    print("{val}{sign}".format(val=round(deg_mdc), sign=degree_sign))


if __name__ == "__main__":
    main()
