#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-30
Description: tree recursion
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-30
"""


# tree recursion <<<
def tree(num):
    '''tree recursion'''
    if num >= 1:
        print(num, end='')
        tree(num - 1)
        tree(num - 1)
# >>>


tree(5)
