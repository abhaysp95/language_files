#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-08
Description: Count the prime numbers digits in the given number
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: date
"""

num = int(input())
count = 0
# if num > 0:
#     while num > 0:
#         r = num%10
#         flag = 0
#         if num == 2:
#             count+=1
#         else:
#             i = 2
#             for i in range(2,r):
#                 if num%i == 0:
#                     flag = 1
#                     break
#             if flag == 0:
#                 count+=1
#     print(count)
if num > 0:
    while num > 0:
        r = num%10
        flag = 0
        if num == 2:
            count += 1
        elif num == 1:
            flag = 1    # 1 is neither prime nor composite
        else:
            i = 2
            for i in range(2, r):
                if r%i == 0:
                    flag = 1
                    break
        if flag == 0:
            count += 1
        num = num//10
    print(count)
