#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-24
Description: learning user defined functions
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-24
"""

# defining function <<<
def add(i, j):
    return i + j
# >>>

# using function <<<
i = int(input('Enter the value of i: '))
j = int(input('Enter the value of j: '))

for x in range(i + 1):
    for y in range(j + 1):
        # print('Sum is: ', add(x, y), end='')
        # taking a return
        res = add(x, y)
        print('Sum is: ', res, end='')
    print()
# >>>
