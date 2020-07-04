#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: keyword parameter in function
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-26
"""

# <<<
# Definition: Using the keyword argument, the argument passed in function call is matched
# with function definition on the basis of the name of the parameter
# >>>

# function creation <<<
def key_func(name, age):
    print('Name is '+name)
    print('Age is ', age)
# >>>

print('Calling in sequence: ')
key_func('abhay', 20)

print('Callin with keyword argument: ')
key_func(age=20, name='abhay')
