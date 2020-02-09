#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-08
Description: Print all the prime numbers in the given range
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-08
"""

# num = int(input("Enter the end for range: "))
# num2 = int(input())
# if num > 1:
#     # i = 2
#     for i in range(num2, num+1):
#         if i == 1:
#             continue
#         # j = 2
#         flag = 0
#         for j in range(2, i):
#             if i == 2:
#                 print(i)
#             else:
#                 if (i%j == 0):
#                     flag = 1
#                     break
#         if flag == 0:
#             print(i)
# The above one is also correct

begin = int(input("Enter the beginging range: "))
end = int(input("Enter the end range: "))

if begin > end:
    begin, end = end, begin
if begin == 1:
    begin += 1
while begin <=end:
    flag = 0
    for i in range(2, begin):
        if begin%i == 0:
            flag = 1
            break
    if flag == 0:
        print(begin)
    begin += 1
