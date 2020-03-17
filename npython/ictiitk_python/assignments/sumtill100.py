#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-17
Description: Print the numbers from 1 till their sum is less than 100
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-17
"""

# logic <<<
sum = 0
for i in range(1, 100):
    sum = sum + i
    if sum >= 100:
        break
    print(i, end='\t')
# >>>
