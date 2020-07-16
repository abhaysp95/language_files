#!/usr/bin/env python3

'''
walk module of os, traversing a directory
'''

import os


def first_example():
    '''first example'''
    for (root, dirs, files) in os.walk('.', topdown=True):
        print(root)
        print(dirs)
        print(files)
        print('-------------------')


def second_example():
    count = 0
    home = os.path.expanduser('~')
    for (root, dirs, files) in os.walk(home, topdown=True):
        for name in files:
            count += 1
            print(os.path.join(root, name))
        for name in dirs:
            print(os.path.join(root, name))
            count += 1
    print(count)


if __name__ == "__main__":
    second_example()
