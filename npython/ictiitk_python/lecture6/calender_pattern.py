#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-18
Description: Don't know why I called it calender pattern
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-18
"""

row = int(input('row: '))
col = int(input('col: '))
for i in range(1, row + 1):
    for j in range(1, col + 1):
        print(j * i, end="\t")
    print()     # next line
