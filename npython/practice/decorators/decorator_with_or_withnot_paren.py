#!/usr/bin/env python3


"""
different methods for calling decorator
"""

from functools import wraps

# version 1
def best_echo_wrapper_count(func=None, count=1):
    """actual decorator function"""
    print(f"Inside the best_echo_wrapper_count: {count}")
    # Branch 1: @decorator using()
    if func is None:
        print('func is None')
        def decorator(func):
            "decorator function"
            print('Inside decorator')
            @wraps(func)
            def wrapper(*args, **kwargs):
                """wrapper function 1"""
                print("Inside wrapper 1")
                for _ in range(count + 1):
                    func(*args, **kwargs)
            return wrapper
        return decorator

    # Branch 2: @decorator not using ()
    @wraps(func)
    def wrapper(*args, **kwargs):
        """wrapper function 2"""
        print("Inside wrapper 2")
        for _ in range(count + 1):
            func(*args, **kwargs)
    return wrapper

# version 2
def outer_decorator0(func=None, count=1):
    """outer_decorator0"""
    if func is None:
        def outer_decorator1(func):
            def wrapper(*args, **kwargs):
                """wrapper"""
                for _ in range(count + 1):
                    func(*args, **kwargs)
            return wrapper
        return outer_decorator1
    def wrapper(*args, **kwargs):
        """wrapper"""
        for _ in range(count + 1):
            func(*args, **kwargs)
    return wrapper


@best_echo_wrapper_count
def hello1(whom):
    """greet hello 1"""
    print(f"Hello 1, {whom}!")


@best_echo_wrapper_count(count=3)
def hello2(whom):
    """greet hello 2"""
    print(f"Hello 2, {whom}")


@outer_decorator0
def hello3(whom):
    """greet hello 3"""
    print(f"Hello 3, {whom}!")


@outer_decorator0(count=2)
def hello4(whom):
    """greet hello 4"""
    print(f"Hello 4, {whom}!")


print("---- Best solution: version 1 -------")
hello1("John")
print("------------------")
hello2("Harry")
print("---- Best solution: version 2 -------")
hello3("Larry")
print("------------------")
hello4("Tim")


# Note: they all will print one more than given count(if you missed)


# both the "outer_decorator0" and "outer_decorator1" functions have exactly
# the same structure. Thus, consider the technique called currying, which
# refers to creating new functions from existing functions by applying
# partial arguments
