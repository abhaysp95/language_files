#!/usr/bin/env python3

'''
some examples of glob in python
'''

import glob


def first_example():
    '''print all python files in current dir'''
    for py in glob.glob("*.py"):
        print(py)


def second_example():
    '''list files with pattern'''
    for py in glob.glob("class[0-9].py"):
        print(py)


def third_example():
    '''limited characters'''
    for py in glob.glob("????.py"):
        print(py)


def fourth_example():
    '''print the directories inside the name folder recursively'''
    for folder in glob.glob('pratice/**/', recursive=True):
        print(folder)


def fifth_example():
    '''generator object'''
    # this methods creates a python generator object which can be
    # used to list files under given directory. Call next()
    # function to print names of files
    gen = glob.iglob("*.py")
    print(type(gen))
    for py in gen:
        print(py)
