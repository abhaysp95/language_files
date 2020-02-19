#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-19
Description: print unique
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-19
"""

arr = []
n = int(input())
for i in range(n):
    num = int(input())
    arr.append(num)
for i in range(n):
    for j in range(0, n - i - 1):
        if (arr[j] > arr[j + 1]):
            arr[j], arr[j+1] = arr[j+1], arr[j]
for i in range(n):
    if (arr[i] == arr[i+1]):
        print(arr[i])
        i += 1
    else:
        print(arr[i])

