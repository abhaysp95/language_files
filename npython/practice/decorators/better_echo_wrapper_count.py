#!/usr/bin/env python3

"""
verbose form of decorator working
"""

def better_echo_wrapper_count(count=1):
    """wrapper count"""
    print(f"Inside better_echo_wrapper_count: {count}")
    def decorator(func):
        print("Inside decorator")
        def wrapper():
            print("Inside wrapper")
            for _ in range(count + 1):
                func()
        return wrapper
    return decorator


@better_echo_wrapper_count(count=3)
def greet():
    """greet function"""
    print("Hi python learner")


@better_echo_wrapper_count()
def foo():
    "foo function"
    print("foo")


@better_echo_wrapper_count
def bar():
    "bar function"
    print("bar")


print("--------------------")
greet()
print("--------------------")
foo()
print("--------------------")
bar()


# basically, you have to call better decorator using parenthesis, like
# better_echo_wrapper_count()
