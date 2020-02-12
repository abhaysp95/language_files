#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-12
Description: pyramid pattern
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-12
"""

n=int(input())
for i in range(1, n+1):
    for j in range(1, n-i):
        if (j <= n-i):
            print(" ")
        # else:
        #     print('_')
    for k in range(1, (2*i)):
        print(k,end="")
    print()
# n=int(input())
# sp=n-1
# t=1
# for i in range(1, n+1):
#     print(' '*sp,end="")
#     for j in range(1, t+1):
#         print(j, end="")
#     print()
#     t+=2
#     sp-=1
