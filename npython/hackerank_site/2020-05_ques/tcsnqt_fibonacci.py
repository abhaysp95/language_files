#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-05-02
Description: fibonacci series
Email: abhaysp9955@gmail.com
Last Edit: 2020-05-02
"""


PROMPT = '> '


# function to get fib <<<
def fib(number):
    '''function will return integer from fibonacci series for given position'''
    # if number == 0:
    #     return 0
    # no need for number == 0, because recursion will
    # never reach for 0
    if number <= 2:
        return 1
    return fib(number - 1) + fib(number - 2)
# >>>


# main function <<<
def main():
    '''main function providing range to fib()'''
    num = int(input(PROMPT).strip())

    result = fib(num)

    print("Fibonacci number on ", num, " is: ", result)
# >>>


if __name__ == "__main__":
    main()
