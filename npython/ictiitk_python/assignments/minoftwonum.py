#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-17
Description: check minimum of two entered numbers
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-17
"""

# logic <<<
x = input('Enter the first number: ')
y = input('Enter the second number: ')

x = float(x)
y = float(y)

if x < y:
    print("The minimum number is first number and it's value is ", int(x))
else:
    print("The minimum number is second number and its value is ", int(y))
# >>>
