#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: using filter high-order function
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-26
"""

# filter function works only on boolean operation satisfying elements
# map function works on every elements

# solution with filter function <<<

lst = list(range(10))

def isgreater(val):
    return val > 5

gtlst = list(filter(isgreater, lst))

print('List is: \n', lst)
print('New list is: \n', gtlst)

# >>>

# solution with lambda function <<<

# lst already declared

def isgreater1(val):
    if val > 4:
        return val

gtlst1 = list(map(isgreater1, lst))

print('Latest list is: \n', gtlst1)

# >>>

gtlst2 = list(filter(lambda x: x > 3, lst))

print('All new list is: \n', gtlst2)
