#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-05
Description: Find out whether the entered number is prime number or not
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-05
"""

# Prime numbers are those numbers which have two factors 1 and the number itself, like 31, 17 etc.

num = int(input("Enter the number: "))
if num <= 0:
    print("WARNING: Enter number greater than 0")
elif num == 2:
    print("Number 2 is prime number")
else:
    i = 2
    flag = 0
    for i in range(i, num//2):
        if num%i == 0:
            flag = 1
            break
        # else:
        #     print("Entered number ", num, "is a Prime Number")
    if flag == 0:
        print("Entered number ", num, "is a Prime Number")
    else:
        print("Entered number ", num, "is a Composite Number")

