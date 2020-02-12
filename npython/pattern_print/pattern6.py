#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-12
Description: some difference w.r.t. pattern5 ques
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-12
"""

num=int(input())
n = 2
current_num=n
for i in range(2, num+2):
    for j in range(1, i):
        current_num-=1
        print(current_num," ",end="")
    print("")
    n+=i
    current_num=n
