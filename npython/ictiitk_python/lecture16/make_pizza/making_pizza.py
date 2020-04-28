#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-26
Description: file to call pizza.py as module
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-26
"""

# these are different ways for importing
# import pizza
# from pizza import make_pizza as mp
import pizza as p


# call pizza.py <<<
def main():
    '''Entering inside main function'''
    # pizza.make_pizza(16, 'veg')
    # pizza.make_pizza(12, 'onion', 'tomato', 'cheese')
    # mp(16, 'veg')
    # mp(12, 'onion', 'tomato', 'cheese')
    p.make_pizza(16, 'veg')
    p.make_pizza(12, 'onion', 'tomato', 'cheese')
# >>>


if __name__ == "__main__":
    print(main.__doc__)
    main()
