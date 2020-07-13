#!/usr/bin/env python3

'''
implementing linear search in python
'''


def search(key, element_list):
    '''search in the list'''
    for position, element in enumerate(element_list):
        if key == element:
            return position
    return -1


def main():
    '''main function'''
    key = 6
    try:
        position = search(key, [3, 4, 7, 8, 5, 9, 1])
        if position == -1:
            raise ValueError
        print(f"Position of key in list is {position}")
    except ValueError:
        print(f"Key {key} not found in the list")


if __name__ == "__main__":
    main()
