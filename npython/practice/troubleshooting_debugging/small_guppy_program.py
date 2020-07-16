#!/usr/bin/env python3

'''
a small program of guppy usage
'''

from guppy import hpy


def main():
    '''main function'''
    heap = hpy().heap()
    print(heap)  # displays first 10 memory usage parameter
    print(heap.more)  # displays next 10 memory usage parameter (if exists)


if __name__ == "__main__":
    main()
