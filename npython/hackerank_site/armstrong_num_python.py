#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-05
Description: Find out whether entered number is armstrong or not
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-05
"""

# Armstrong numbers are those numbers whose sum of individual digit's cube is equal to the number itself like 153
num = int(input("Enter the numbers: "))
if num < 0:
    print("Enter the numbers greater than 0")
else:
    n = num
    new_num = 0
    while num > 0:
        r = num%10
        num = num//10
        new_num = new_num + (r**3)
    if new_num == n:
        print("Entered number ", n, "is an armstrong number")
    else:
        print("Entered number ", n, "is not an armstrong number")
