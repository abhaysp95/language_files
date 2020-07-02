#!/usr/bin/env python

"""
Extract new revision number and find avg as integer
"""

import re


def get_numlist(fname):
    '''get list of new revision number'''
    try:
        fhand = open(fname, 'r')
    except:
        print(f"file {fname} not found here")
        exit()

    num_lst = list()
    for line in fhand:
        line = line.rstrip()
        number = re.findall(r"New Revision:\s([0-9]+)", line)
        # number here is list
        if len(number) == 0:
            continue
        num_lst.append(''.join(number))

    return num_lst


def get_average(nlist):
    '''get average of numbers in number list'''
    nlist = [float(num) for num in nlist]
    print("Average is {0:0d}".format(int(sum(nlist) / len(nlist))))


def main():
    '''inside main function'''
    res_list = get_numlist(input('Enter the file name: '))
    get_average(res_list[:])


if __name__ == "__main__":
    main()
