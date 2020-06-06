#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
get earned money by Raghav
"""


def main():
    '''inside main function'''
    tot_shoes = int(input())
    shoe_sizes = [int(x) for x in input().split(' ')]
    tot_customer = int(input())
    to_purchase = {}
    # for _ in range(tot_customer):
