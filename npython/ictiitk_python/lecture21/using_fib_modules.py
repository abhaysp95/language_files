#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-05-08
Description: using fib_modules
Email: abhaysp9955@gmail.com
Last Edit: 2020-05-08
"""

import fib_modules


# main function
def main():
    '''Inside main function'''
    print(fib_modules.fib_rec(5))
    print(fib_modules.fib_iter(6))
    get_lst = []
    get_lst = fib_modules.fib_upto(7)
    print(get_lst)

    print(fib_modules.__name__)  # this will return the module name
    # in case if it is necessary


if __name__ == "__main__":
    main()
