#!/usr/bin/env python3


"""
decorators as class
"""

from functools import wraps

class Repeat:
    """Repeat class"""
    def __init__(self, num):
        self.num = num

    def __call__(self, func):
        @wraps(func)
        def repeater(*args, **kwargs):
            """repeater function"""
            for _ in range(self.num):
                func(*args, **kwargs)
        return repeater


@Repeat(num=2)
def morning_greet(person):
    """greet person the morning"""
    print(f"Good Morning, {person}!")


@Repeat(num=3)
def afternoon_greet(person):
    """greet afternoon"""
    print(f"Good Afternoon, {person}!")


morning_greet("Jason")
afternoon_greet("Kelly")
print(morning_greet.__doc__)
