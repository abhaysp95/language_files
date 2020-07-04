#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-30
Description: get power with loop
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-30
"""

PROMPT = '> '


# function for recursion <<<
def get_power(first_num, second_num):
    '''get power of first_num'''
    result = 1
    while second_num > 0:
        if first_num == '1':
            result = 1
            break
        result = result * first_num
        second_num -= 1
    print("Result is: ", result)
# >>>


# main function <<<
def main():
    '''Entering in main function'''
    fnum = int(input(PROMPT))
    snum = int(input(PROMPT))
    get_power(fnum, snum)
# >>>


if __name__ == "__main__":
    main()
