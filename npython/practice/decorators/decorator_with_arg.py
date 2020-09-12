#!/usr/bin/env python3

'''
decorator with argument
'''

import time
from functools import wraps


def logging_time(unit):
    '''decorator function'''
    def logger(func):
        @wraps(func)
        def inner_logger(*args, **kwargs):
            '''function that logs time'''
            start = time.time()
            func(*args, **kwargs)
            scaling = 1000 if unit == "ms" else 1
            print(f"Calling {func.__name__}: {(time.time() - start) * scaling:.5f}")
        return inner_logger
    return logger


@logging_time("ms")
def calculate_sum_ms(num):
    '''sum of 0 to n - 1'''
    return sum(range(num))


@logging_time("s")
def calculate_sum_s(num):
    '''sum of 0 to n - 1'''
    return sum(range(num))


calculate_sum_ms(100000)
calculate_sum_s(100000)


# reason for adding another layer to get the decorator to accept is
# that the decoration process is chaining the function call.

# Calling "logging_time("ms")" would allow us to get the "logger" function,
# which has exactly the same function signature as the decorator function
# that we defined earlier

# Note that, at this time decorator requires must to be passed with the arg
