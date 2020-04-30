#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-30
Description: recursion problem, get power of number
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-30
"""

PROMPT = '> '


# function to get power <<<
def get_power(first_num, second_num):
    '''get power of the first_num'''
    if first_num == 1 or second_num == 0:
        return 1
    else:
        return first_num * get_power(first_num, second_num - 1)
    # return result
# >>>


# main function <<<
def main():
    '''Entering in main function'''
    fnum = int(input(PROMPT))
    snum = int(input(PROMPT))

    result = get_power(fnum, snum)
    print("Result is: ", result)
# >>>


if __name__ == "__main__":
    main()
