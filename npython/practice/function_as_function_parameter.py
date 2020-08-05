#!/usr/bin/env python3

'''
Passing a function as parameter for another function
'''

# In python, every parameter of a function is a reference to an object and
# functions are objects as well, we can pass functions - or better
# "references to functions" - as parameters to a function.

import math


def function_recieving_another_function_as_arguement(func):
    '''call it as a primary function'''
    print("The function " + func.__name__ + " was passed to this function")
    res = 0
    for num in [1, 2, 2.5]:
        res += func(num)
    return res


print(function_recieving_another_function_as_arguement(math.sin))
print(function_recieving_another_function_as_arguement(math.cos))
