#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-26
Description: Print tuple sorted according to their sum
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-26
"""

n=int(input())
lst=[]
for i in range(n):
    tup=tuple(map(int, input().split()))
    lst.append(tup)
for x in range(len(lst)):
    for y in range(x+1, len(lst)):
        if(sum(lst[x])>sum(lst[y])):
            temp = lst[x]
            lst[x] = lst[y]
            lst[y] = temp
print(lst)
