#!/usr/bin/env python3

'''
same program as log_time.py but with args usage
'''

import time


def logging_time(func):
    '''decorator that logs time'''
    def logger(*args, **kwargs):
        '''function that logs time'''
        start = time.time()
        func(*args, **kwargs)
        print(f"Calling {func.__name__}: {time.time() - start:.5f}")
    return logger


@logging_time
def calculate_sum():
    '''calculate sum, no args'''
    return sum(range(1000000))


@logging_time
def calculate_sum_num(num):
    '''calculate sum to num'''
    return sum(range(num))


@logging_time
def say_hi(whom, greeting="Hello"):
    '''greet person'''
    print(f"{greeting}, {whom}!")


calculate_sum()
calculate_sum_num(1000000)
say_hi("John", greeting="Hey")
