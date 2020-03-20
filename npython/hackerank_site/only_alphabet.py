#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-20
Description: Remove everything except alphabet
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-20
"""

# variable declaration
word = input('Enter the string: ')

# iteration <<<
for i in word:
    if i >= 'a' and i <= 'z':
        print(i, end='')
    elif i >= 'A' and i <= 'Z':
        print(i, end='')
# >>>

# how to do comparision with ascii code in python?
