#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-19
Description: Another if else program
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: date
"""

# logic <<<
age = int(input('Enter the age: '))

if age > 0 and age < 2:
    print("It's a baby")
elif age >= 2 and age < 4:
    print('He is a toddler')
elif age >= 4 and age <= 13:
    print('She is a kid')
elif age >= 13 and age <= 20:
    print('You have grown to a teenager')
elif age >= 20 and age < 65:
    print('You are now officially adult')
elif age >= 65:
    print('You are elder')
else:
    print('Enter the age greater than 0')
# >>>

# search for simplify chained comparision between operand
