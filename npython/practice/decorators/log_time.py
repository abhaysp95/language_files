#!/usr/bin/env python3

'''
time logging a function
'''

# decorators are functions that modify other function's behaviors without
# changing their core operations

import time

def logging_time(func):
    '''decorator that logs time'''
    def logger():
        '''function that logs time'''
        start = time.time()
        func()  # execute the got function
        print(f"Calling {func.__name__}: {time.time() - start:.5f}")
        print(f"{start:.5f}")
    return logger

@logging_time
def calculate_sum():
    '''calculate the sum'''
    return sum(range(1000))

calculate_sum()

# problem with above code is that it assumes that decorated function 'func()'
# doesn't requires any input argument

# @logging_time
# def calculate_sum_n(n):
    # '''calculate sum to n'''
    # return sum(range(n))

# calculate_sum_n(10000)

# as you can see the above code will give error for positional argument
# To address this issue, use '*args' and '**kwargs' with decorator function
# they can capture all kinds of function signature
