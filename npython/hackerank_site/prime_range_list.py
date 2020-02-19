#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-19
Description: Tell prime num count in range in list
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-19
"""

arr = []
n = int(input())
for i in range(n):
    num = int(input())
    arr.append(num)
c = 0
for i in range(n):
    flag = 0
    if (arr[i] == 2):
        flag = 0
    elif (arr[i] == 1):
        flag = 1
    else:
        for j in range(2, arr[i]):
            if (arr[i] % j == 0):
                flag = 1
                break
        if flag == 0:
            c += 1
print(c)
