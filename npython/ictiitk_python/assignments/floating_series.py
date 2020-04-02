#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-02
Description: generate a floating number series
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-04-02
"""

C = 0
# function <<<
def generateNext(d, num, i):
    num = num + d*i
    return num
# >>>

C = float(input('Please enter the starting number of your series: \n'))
s = float(input('Please input the d for your series: \n'))
print ('The series produced by this method is: ')

for r in range(int(input('Enter the range: '))):
    print(generateNext(s, C, r), end='')
    print(', ', end='')
