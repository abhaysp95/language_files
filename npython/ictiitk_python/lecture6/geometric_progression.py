#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-18
Description: Geometric progression
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-18
"""

r = float(input('r = '))
a = int(input('a = '))
n = int(input('n = '))

j = 0
for i in range(a, a + n):
    print(a*(r**j), "\t")
    j += 1

# or, another logic
# take input r, a, n
# term = a
# print(term)
# for i in range(1, n):
#   term = term * r
#   print(term)
