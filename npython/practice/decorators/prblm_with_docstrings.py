#!/usr/bin/env python3

'''
effect on docstring of decorators
'''

import time


def logging_time(func):
    '''decorator function for logging time'''
    def logger(*args, **kwargs):
        '''time logging function'''
        start = time.time()
        func(*args, **kwargs)
        print(f"Calling func {func.__name__}: {time.time() - start:.5f}")
    return logger


@logging_time
def say_hello(whom):
    "greet someone"
    print(f"Hello, {whom}")


print(say_hello.__doc__)
# should print "greet someone"
# but printing "time loggin function", showing of inner function
# it's like say_hello = logging_time(say_hello)


# lets solve the problem by using another decorator function "wraps" in next file solution_decorator_problem.py
