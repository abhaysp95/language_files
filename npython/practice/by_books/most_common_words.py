#!/usr/bin/env python

import string


def first_method(fname):
    try:
        fhand = open(fname, 'r')
    except:
        print('File {} not found here'.format(fname))
        exit()

    common = dict()
    for line in fhand:
        line = line.translate(line.maketrans('', '', string.punctuation))
        print(line)
        # case insensitive
        line = line.lower()
        words = line.split()
        # for word in words:
        # if word in common:
        # common[word] += 1
        # else:
        # common[word] = 1
        # this can be written as below
        for word in words:
            common[word] = common.get(word, 0) + 1

    return common


def main():
    res_dict = first_method(input('Enter the filename: '))
    print(res_dict)


main()
