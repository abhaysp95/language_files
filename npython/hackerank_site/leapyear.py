#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-24
Description: leap year
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-24
"""

cyear = int(input())
if cyear % 4 != 0:
    r = cyear % 4
    cyear += (4 - r)
year = []
print(cyear)
for i in range(0, 60, 4):
    if (cyear + i) % 4 == 0:
        num = cyear + i
        print(num)
        year.append(num)
print(year)
