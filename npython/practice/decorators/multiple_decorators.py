#!/usr/bin/env python3

"""
multiple decorators
"""

# we can just stack the decorators above the to-be decoratred functions


import time
from functools import wraps


def logging_time(unit):
    """decorator function"""
    def logger(func):
        @wraps(func)
        def inner_logger(*args, **kwargs):
            """inner logger function"""
            start = time.time()
            func(*args, **kwargs)
            scale = 1000 if unit == "ms" else 1
            print(f"Calling {func.__name__}: {(time.time() - start) * scale:.5f}")
        return inner_logger
    return logger


def repeat(func):
    """decorator that repeats function call twice"""
    @wraps(func)
    def repeater(*args, **kwargs):
        """repeater function"""
        func(*args, **kwargs)
        func(*args, **kwargs)
    return repeater


@logging_time("ms")
@repeat
def say_hi(whom):
    """greet"""
    print(f"Hi, {whom}!")


@repeat
@logging_time("s")
def say_hello(whom):
    """great"""
    print(f"Hi, {whom}!")


say_hi("John")
print("---------------")
say_hello("Doe")


# when having multiple decorators, the order of applying the decorator
# is based on proximity
