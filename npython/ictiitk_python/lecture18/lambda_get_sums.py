#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-27
Description: getting summation using lambda function
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-27
"""


# function to get summation <<<
def summation_is(number, function):
    '''computes f(0) + f(1) + ... + f(n)'''
    sum_is = 0
    for num in range(1, number + 1):
        sum_is = sum_is + function(num)
    return sum_is
# >>>


# main function <<<
def main():
    '''Entering in main function'''
    print(summation_is(10, lambda x: x))
    print(summation_is(10, lambda x: x * x))
    print(summation_is(10, lambda x: x * x * x))
# >>>


if __name__ == "__main__":
    main()
