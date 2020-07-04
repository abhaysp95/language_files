#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: Using map function
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-26
"""

# function declaration <<<

def square(val):
    return val**2

lst = list(range(10))
# this should be defined before use of it

result_lst = list(map(square, lst))
# >>>

# function calling and preparation <<<

print('Normal list: \n', lst)

print('Square list: \n', result_lst)

# >>>
