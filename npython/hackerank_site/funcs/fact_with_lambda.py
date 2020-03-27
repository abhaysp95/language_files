#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: Finding factorail of a num with lambda
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-26
"""

# varible declaration <<<
fact = 1
num = int(input())
# >>>

# function <<<
res = lambda x, y: x * y
# >>>

# loop <<<
for i in range(1, num):
    fact = res(fact, i + 1)
# >>>

print('Factorial is: ', fact)
