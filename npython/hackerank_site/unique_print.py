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
for i in range(0, n):
    for j in range(0, n - i - 1):
        if (arr[j] > arr[j + 1]):
            arr[j], arr[j+1] = arr[j+1], arr[j]
i = 0
if i != n-1:
    for i in range(0, n - 1):
        print("i is: ", i)
        if arr[i] == arr[i+1]:
            print("\nI'm in if")
            print(arr[i])
            i += 1
            # continue
        else:
            print("\nI'm in else")
            print(arr[i])
else:
    print(arr[i])
