#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-05-08
Description: different fibonacci modules
Email: abhaysp9955@gmail.com
Last Edit: 2020-05-08
"""


# recursive fibonacci function
def fib_rec(number):
    '''recursive fibonacci'''
    if number <= 2:
        return 1
    return fib_rec(number - 1) + fib_rec(number - 2)


# iterative fibonacci function
def fib_iter(number):
    '''iterative fibonacci'''
    cur_num, next_num = 0, 1
    for _ in range(number):
        cur_num, next_num = next_num, cur_num + next_num
    return cur_num


# give fibonacci series upto give number
def fib_upto(number):
    '''return list of fibonacci series upto given number'''
    cur_num, next_num = 1, 1
    fib_list = []
    while cur_num <= number:
        fib_list.append(cur_num)
        cur_num, next_num = next_num, cur_num + next_num
    return fib_list


def __print__():
    '''this function will not be imported in other module'''
    print('This function starts with underscore')


if __name__ == "__main__":
    print('Inside module file')
    import sys
    print(fib_iter(int(sys.argv[1])))
else:
    print('Outside module file')
