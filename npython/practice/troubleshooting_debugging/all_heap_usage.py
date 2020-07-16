#!/usr/bin/env python3

'''
script to get all the heap objects
'''

from guppy import hpy


def get_objects():
    '''get all the heap objects'''
    heap_usage = hpy().heap()
    print(heap_usage)
    heap_usage_contents = str(heap_usage.more).split('\n')

    while (len(heap_usage_contents[1:]) > 0):
        print()
        heap_usage = heap_usage.more
        print(heap_usage)
        heap_usage_contents = str(heap_usage.more).split('\n')


if __name__ == "__main__":
    get_objects()
