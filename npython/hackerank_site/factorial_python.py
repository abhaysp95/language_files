#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-05
Description: Making a factorial progrma
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-05
"""

num = int(input("Enter the number: "))

if num>=1 and num<=100:
    fact = 1
    for i in range(1,num+1):
        fact = fact*i
    print("Factorial of ", num, " is => ", fact)
elif num == 0:
    print("Factorial of 0 is => 0")
else:
    print("WARNING: Enter number in range")
