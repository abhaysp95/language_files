#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-05-05
Description: recursive function, tower of hanoi
Email: abhaysp9955@gmail.com
Last Edit: 2020-05-05
"""

PROMPT = '> '
cycle = 0


# function for tower of hanoi
# <<<
def toh(count, first, second, third):
    '''function to get tower of hanoi count moves'''
    global cycle
    if count > 0:
        toh(count - 1, first, third, second)
        print('Moving last disk from ', first, ' to ', third)
        cycle += 1
        toh(count - 1, second, first, third)
# >>>


# main function
# <<<
def main():
    '''Entering in main function'''
    print('Enter the disk count: ')
    disk_count = int(input(PROMPT))
    toh(disk_count, 1, 2, 3)
    print('Total cycle is: ', cycle)
# >>>


if __name__ == "__main__":
    main()
