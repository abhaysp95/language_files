#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-30
Description: getting fibonacci series with recursion
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-30
"""


# function to get fibonacci series <<<
def get_fibonacci(num_range):
    '''get fibonacci series according to given range'''
    # third_num = first_num + second_num
    # first_num = second_num
    # second_num = third_num
    # if num_range > 0:
    #     get_fibonacci(first_num, second_num, num_range - 1)
    # print(first_num, ", ", second_num, ", ", end="")
    # print(third_num, ", ", end="")
    if num_range <= 1:
        return num_range
    else:
        return get_fibonacci(num_range - 1) + get_fibonacci(num_range - 2)
# >>>


# main function <<<
def main():
    '''Entering in main function'''
    given_range = int(input('Enter the range: '))

    val = get_fibonacci(given_range)
    print(val)
# >>>


if __name__ == "__main__":
    main()
