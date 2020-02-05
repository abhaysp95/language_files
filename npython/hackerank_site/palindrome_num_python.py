#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-05
Description: Finding whether a number is palindrome or not
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-05
"""

# A palindrome number whether read from right or left is same like 121, 23432 etc.

num = int(input("Enter the number: "))
n = num
new_num = 0
if num < 1:
    print("WARNING: Enter number above or equal to 1")

else:
    while num > 0:
        r = num % 10
        num = num // 10
        new_num = new_num*10 + r
    if n == new_num:
        print("Entered Number is Palindrome")
    else:
        print("Entered Number is not Palindrome")
