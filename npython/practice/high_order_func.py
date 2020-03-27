#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: practice for high order function
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-26
"""

# function declaration <<<
def calculation(given_func, num):
    sum = 0
    for i in range(num + 1):
        sum = sum + given_func(i)
    # print('Sum is: ', sum)
    return sum

def linear(val):
    return val

def square(val):
    return val**2

def cube(val):
    return val**3
# >>>

print('Calling linear: ', calculation(linear, 10))
print('Calling square: ', calculation(square, 8))
print('Calling cube: ', calculation(cube, 6))
