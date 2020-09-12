#!/usr/bin/env python3

"""
decorator with currying technique
"""


from functools import wraps, partial

# define constructor function
def best_echo_wrapper_count(func=None, count=1):
    """best version for decorator function"""
    if func is None:
        return partial(best_echo_wrapper_count, count=count)
    @wraps(func)
    def wrapper(*args, **kwargs):
        """wrapper function"""
        for _ in range(count + 1):
            func(*args, **kwargs)
    return wrapper


@best_echo_wrapper_count
def get_better(times):
    """test function"""
    print(f"Get better: {times}")


@best_echo_wrapper_count(count=3)
def get_better2(times):
    """test function"""
    print(f"Get better2: {times}")


get_better("first")
print(get_better.__doc__)
get_better2("second")
print(get_better2.__doc__)
