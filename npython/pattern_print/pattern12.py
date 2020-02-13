#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-13
Description: Right half pyramid with capital alphabets
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-13
"""

# num = 65
# print("Enter the number for rows: ")
# rows = int(input())
# j = 1
# for i in range(1, rows+1):
#     print(chr(num)*j, end="")
#     j += 1
#     print()

print("Enter the number for rows: ")
num = 65
rows = int(input())
for i in range(1, rows+1):
    for j in range(1, i+1):
        print(chr(num), " ", end="")
        num += 1
    print()
