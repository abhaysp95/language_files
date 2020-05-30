#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
understanding product for itertools module
"""

from itertools import product


def first_funct(farr, sarr):
    '''first function'''
    return [[x, y] for x in farr for y in sarr]


# first function with the help of itertools.product() can be written as
def second_func(farr, sarr):
    '''second func'''
    return list(product(farr, sarr))


# with repeat keyword
def third_func(farr):
    '''third func'''
    return list(product(farr, repeat=3))


def fourth_func(farr, sarr):
    '''fourth func'''
    # this will generate product for product of farr, sarr as
    # product(result, repeat=2), where result = product(farr, sarr)
    return list(product(farr, sarr, repeat=2))


def main():
    '''inside main function'''
    # result = second_func(input().split(' '), input().split(' '))
    flst = list(map(int, input().split(' ')))
    slst = list(map(int, input().split(' ')))
    result = second_func(flst, slst)
    for tup in result:
        print(tup, end=' ')


if __name__ == "__main__":
    main()
