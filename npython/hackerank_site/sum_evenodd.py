#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-19
Description: sum of even and odd in list
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: date
"""

arr = []
n = int(input(' Enter the count: '))
for i in range(n):
    num = int(input())
    arr.append(num)
esum=0
osum=0
for i in range(n):
    if (arr[i]%2 == 0):
        esum += arr[i]
    else:
        osum += arr[i]
print("Even sum is: ", esum)
print("Odd sum is: ", osum)
