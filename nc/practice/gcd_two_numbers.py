#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-02
Description: get gcd of two numbers
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-04-02
"""

# <<<
a = int(input('Enter the first number: '))
b = int(input('Enter the second number: '))

gcd = 1

def get_min(a, b):
    if a > b:
        return 1
    else:
        return 0

def get_gcd(a, b):
    if a == 0:
        print('gcd is: 0')
    while b != 0:
        if get_min(a, b) > 0:
            a = a - b
        else:
            b = b - a
    return a

print('gcd is: ', get_gcd(a, b))
# >>>
