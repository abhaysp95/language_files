#!/usr/bin/env python3

'''
implement binary search(interpolation search)
for binary search list must be sorted
'''


def search(key, element_list):
    '''search the element'''
    start = 0
    end = len(element_list) - 1

    while start < end:
        mid = (start + end) // 2
        if element_list[mid] == key:
            return mid + 1
        if key > element_list[mid]:
            start = mid
        else:
            end = mid
    return -1


def main():
    '''main function'''
    key = 5
    elements = [1, 3, 4, 5, 7, 8, 9]
    try:
        position = search(key, elements)
        if position == -1:
            raise ValueError
        print(f"Key {key} found in position {position}")
    except ValueError:
        print(f"Key {key} not found in the element list")


if __name__ == "__main__":
    main()
