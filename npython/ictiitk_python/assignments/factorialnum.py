#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-17
Description: Print factorial of given num
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-17
"""

# logic <<<
try:
    x = int(input('Enter the number to find factorial of: '))
    if x >= 0:
        fact = 1
        for i in range(x, 0, -1):
            fact = fact * i
        print('The factorial is:', fact)
    else:
        print('Factorial below 0 is not defined')
except TypeError:
    print('Data not provided correctly')
# >>>
