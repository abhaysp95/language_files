#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: another lambda function example
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-26
"""

# return max of two <<<
max_ele = lambda x, y: x if x > y else y
# >>>

# function calling:
x = int(input('Enter the first number: '))
y = int(input('Enter the second number: '))
print('Max element is: ', max_ele(x, y))
