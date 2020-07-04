#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: Function with default argument
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-26
"""

# function declaration <<<
def default_func(name, age, addr="PrayagRaj"):
    # above is a function which contains default argument addr
    print('Name is: '+name)
    # since, name is a type string we can use + instead of , it's a concatenation
    print('Age is: ', age)
    # here we can't use +
    print('Address is: '+addr)
# >>>

# function calling

name = input('Enter the name: ')
age = int(input('Enter the age: '))

choice = input('Do you want to enter address: \n"y" for yes\n"n" for no\n')
if choice == 'y':
    addr = input('Enter the address: ')
    default_func(name, age, addr)
else:
    default_func(name, age)
