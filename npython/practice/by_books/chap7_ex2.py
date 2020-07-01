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
            # print(re.findall(r'[\d\.\d]+', line))
            # print(''.join(re.findall(r'[\d\.\d]+', line)))
            sum = sum + float(''.join(re.findall(r'[\d\.\d]+', line)))
            count = count + 1
    print('Completed!')
    print('Average is %.9f' % (sum / count))

    file_is.close()


def second_method(fname):
    if fname == "na na boo boo":
        print("NA NA BOO BOO TO YOU - You have been punk'd!")
        exit()
    file_is = open(fname, 'r')
    count = 0
    sum = 0.0

    for line in file_is:
        if line.startswith('X-DSPAM-Confidence:'):
            sum = sum + float(line.strip().split(': ')[-1])
            count = count + 1
    print('Completed')
    print('Average is %.9f' % (sum / count))
    file_is.close()


def third_method(fname):
    if fname == "na na boo boo":
        print("NA NA BOO BOO TO YOU - You have been punk'd!")
        exit()
    file_is = open(fname, 'r')
    num_lst = []

    for line in file_is:
        if line.startswith('X-DSPAM-Confidence:'):
            num_lst.append(float(line.strip().split()[-1]))
    print('Completed')
    print('Average is %9f' % (sum(num_lst) / float(len(num_lst))))
    file_is.close()


def main():
    #third_method(input('Enter the file name: '))
    first_method()


if __name__ == "__main__":
    main()
