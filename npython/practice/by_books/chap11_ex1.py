#!/usr/bin/env python

"""
simulating 'grep' operation
"""

import re


def simulate_grep(operation):
    '''print count of lines that matched patterns'''
    fname = 'mbox-short.txt'
    try:
        fhand = open(fname, 'r')
    except:
        print('File {} not found, try opening another'.format(fname))

    lcount = 0
    for line in fhand:
        line = line.rstrip()
        if re.search(operation, line):
            lcount += 1

    if lcount == 0:
        print(f'{fname} doesn\'t have any line that matched {operation}')
    else:
        print(f'{fname} had {lcount} lines that matched {operation}')

    fhand.close()


def main():
    '''inside main function'''
    simulate_grep(input('Enter the regex: '))


if __name__ == "__main__":
    main()
