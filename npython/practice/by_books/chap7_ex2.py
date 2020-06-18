#!/usr/bin/env python

import re


def first_method():
    fname = input('Enter the file name: ')
    file_is = open(fname, 'r')
    count = 0

    # numbers = []
    sum = 0.0

    for line in file_is:
        if line.startswith('X-DSPAM-Confidence:'):
            # num = [float(x) for x in line.split() if x.isdigit()]
            # numbers.append(','.join(re.findall(r'[\d\.\d]+', line)))
            sum = sum + float(''.join(re.findall(r'[\d\.\d]+', line)))
            count = count + 1
    print('Completed!')
    print('Average is %.9f' % (sum / count))

    file_is.close()


def second_method(fname):
    file_is = open(fname, 'r')
    count = 0
    sum = 0.0

    for line in file_is:
        if line.startswith('X-DSPAM-Confidence:'):
            sum = sum + float(line.strip().split(': ')[-1])
            count = count + 1
    print('Completed')
    print('Average is %.9f' % (sum / count))


def main():
    second_method(input('Enter the file name: '))

if __name__ == "__main__":
    main()
