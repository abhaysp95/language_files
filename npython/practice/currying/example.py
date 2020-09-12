#!/usr/bin/env python3

"""
example of currying
"""

def add_up(num1, num2):
    """add num"""
    sum_n = num1 + num2
    return sum_n


# define partial function that adds seven
add_seven = lambda x: add_up(7, x)
print(add_seven(10))
print(add_seven(72))


# or instead of lambda, you can just use regular function
def add_eight(num):
    """add num"""
    return add_up(8, num)

print(add_eight(10))
