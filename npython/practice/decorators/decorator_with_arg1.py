#!/usr/bin/env python3

"""
modified version of decorator_with_arg.py
"""

import time
from functools import wraps, partial


# decorator function
def logging_time(func=None, unit="s"):
    """decorator for logging time
    :param: func => function
    :param: unit => Ms = mili second
                    ms = micro second
                    ps = pico second
    """
    if func is None:
        return partial(logging_time, unit=unit)
    @wraps(func)
    def logger(*args, **kwargs):
        """actual time logger function"""
        if unit == "Ms":
            scaling = 1000
        elif unit == "Ms":
            scaling = 1000000
        elif unit == "ps":
            scaling = 1000000000
        else:
            scaling = 1
        start = time.time()
        func(*args, **kwargs)
        print(f"Called function {func.__name__}: {(time.time() - start) * scaling:.5f}")
    return logger


# it's equivalent to calling logging_time()
@logging_time
def say_hello_no(whom):
    """greet function(no)"""
    print(f"Hello(no), {whom}!")


# it's equivalent to calling logging_time()
@logging_time(unit="ms")
def say_hello_ms(whom):
    """greet function(ms)"""
    print(f"Hello(ms), {whom}!")


@logging_time(unit="ps")
def say_hello_ps(whom):
    """greet function(ps)"""
    print(f"Hello(ps), {whom}!")


say_hello_no("John")
say_hello_ms("Dwayne")
say_hello_ps("Kurt")
