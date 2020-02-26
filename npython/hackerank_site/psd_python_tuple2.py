#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: <++>
Description: <++>
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: <++>
"""

n = int(input())
lst = []
lst = tuple(map(int, input().split()))
sumis = sum(lst)
print("1" if sumis%2==0 else "0")
