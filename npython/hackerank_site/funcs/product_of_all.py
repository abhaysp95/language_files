#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: print product of all elements in list using lambda
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-26
"""

# reduce (red(func,seq)) is used to apply a particular sequence to all the elements list

import functools

# input <<<
nums = input('Enter space separated numbers: \n')
lst = list(map(int, nums.split()))
# >>>

# <<<
product = functools.reduce(lambda x, y: x * y, lst)
print(product)
# >>>
