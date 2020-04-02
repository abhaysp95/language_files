#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-02
Description: get all the prime number in given range
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-04-02
"""

# function <<<
def getprime(a, b):
    for i in range(a, b + 1):
        flag = 0
        for j in range(2, (i // 2) + 1):
            if i % j == 0:
                flag = 1
                break
        if flag == 0:
            print(i, end='')
            print(', ', end='')
# >>>

a = int(input('Enter the minimun limit: '))
b = int(input('Enter the max limit: '))

if a <= 1:
    a = 2
if b <= 1:
    b = 2

getprime(a, b)
