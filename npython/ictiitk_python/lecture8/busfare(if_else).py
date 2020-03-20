#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-19
Description: A simple if else program
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-19
"""

# logic <<<
age = int(input('Enter the age: '))

if age < 4:
    print("Ticket for age ", age, " is free.")
elif age < 18:
    print(f"Ticket for age {age} will cost 25 rs")
else:
    print("Ticket will cost 40 rs.")
# >>>
