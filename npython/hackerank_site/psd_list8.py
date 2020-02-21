#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-20
Description: Printing Words for numbers
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-20
"""

num = input()
numbers = ['zero','one','two','three','four','five','six','seven','eight','nine']
lst = list(num)

for i in lst:
    print(numbers[int(i)], end=' ')
