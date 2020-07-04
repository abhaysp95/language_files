#!/usr/bin/env python

from count_word_dict1 import get_dict


def sort_dict(get_dict):
    lst = list()
    for key, value in get_dict.items():
        # or for key, value in list(get_dict.items()):
        lst.append((value, key))
    # print(lst)
    lst.sort(reverse=True)
    return lst


def print_style(got_lst, wcount=10):
    print('\n{}\t{}\n'.format('Words', 'Repition'))
    for value, key in got_lst[:wcount]:
        print('%s: %s' % (key, value))
    print()


def main():
    res_dict = get_dict(input('Enter the filename: '))
    res_list = sort_dict(res_dict)
    word_count = input('Enter the number of maximum words: ')
    print_style(res_list[:], int(word_count))  # not giving orignal list
    # print(res_dict)


# not giving orignal list
if __name__ == "__main__":
    main()
