#!/usr/bin/env python3

'''
solution of docstring problem with decorators
'''

import time
from functools import wraps


def logging_time(func):
    '''decorator function'''
    # wrapping the to be decoratored function (func arg)
    @wraps(func)
    def logger(*args, **kwargs):
        '''time logging function'''
        start = time.time()
        func(*args, **kwargs)
        print(f"Calling {func.__name__}: {time.time() - start:.5f}")
    return logger


@logging_time
def say_hello(whom):
    "greet"
    print(f"Hello, {whom}!")


print(say_hello.__doc__)
