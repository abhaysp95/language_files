#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-27
Description: getting different types of sums
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-27
"""


# function to get summantion <<<
def summation_num(number, func):
    '''computes func(0) + func(1) + ... + func(n)'''
    sum_is = 0
    for num in range(1, number + 1):
        sum_is = sum_is + func(num)
    return sum_is
# >>>


# function for identity <<<
def get_identity(num):
    '''returns itself'''
    return num
# >>>


# function to get square <<<
def get_square(num):
    '''returns square of the give number'''
    return num * num
# >>>


# function to get cube <<<
def get_cube(num):
    '''returns cube of given number'''
    return num * num * num
# >>>


if __name__ == "__main__":
    print("Running as independent script(program)")
    print(summation_num(5, get_identity))
    print(summation_num(5, get_square))
    print(summation_num(5, get_cube))
else:
    print("Running as imported module")
