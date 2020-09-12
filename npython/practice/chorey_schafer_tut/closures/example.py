#!/usr/bin/env python3


"""
closure example
"""

def make_multiplier(co_eff):
    """outer function"""
    product = 1
    def multiplier():
        nonlocal product
        product *= co_eff
        return product
    return multiplier


multiplier3 = make_multiplier(3)
print(multiplier3())
print(multiplier3())
print(multiplier3())
print(multiplier3.__code__.co_freevars)
print(multiplier3.__closure__[1].cell_contents)


# closure remembers the state of the product after its last use
