#!/usr/bin/env python3

'''
return all list of names that occured twice, case-insensitive
'''

import sys
import cProfile, pstats, io


def read_names(src):
    ''' read name '''
    with open(src, 'r') as file:
        return file.read().splitlines()

def is_duplicate(needle, haystack):
    ''' if duplicate name in names list '''
    for name in haystack:
        if needle.lower() == name.lower():
            return True
    return False

def find_duplicate_names(src='mname.txt'):
    ''' driving function to find duplicate name '''
    names = read_names(src)
    duplicates = []
    while names:
        name = names.pop()
        if is_duplicate(name, names):
            duplicates.append(name)
    return duplicates

def profile(func):
    ''' decorator of cProfile '''
    def inner(*args, **kwargs):
        pr = cProfile.Profile()
        pr.enable()
        return_val = func(*args, **kwargs)
        pr.disable()
        s = io.StringIO
        sortby = "cumulative"
        ps = pstats.Stats(pr, stream=s).sort_stats(sortby)
        ps.print_stats()
        print(s.getvalue())
        return return_val
    return inner

@profile
def main():
    ''' driving function'''
    try:
        if sys.argv[1] == "--name" or "-n":
            print(find_duplicate_names())
    except IndexError:
        count = 0
        for _ in find_duplicate_names():
            count += 1
        print("duplicate name count: ", count)

if __name__ == "__main__":
    main()
