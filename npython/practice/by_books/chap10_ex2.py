#!/usr/bin/env python

"""
print out the count of hours one per line
"""


def getHourInDict(fname):
    '''get data inside dict'''
    try:
        fhand = open(fname, 'r')
    except:
        print('File not present here')
        exit()

    data_dict = dict()

    for line in fhand:
        if not line.startswith('From'):
            continue
        words = line.strip().split()
        if len(words) < 3:
            continue
        hour = words[5].split(':')[0]
        data_dict[hour] = data_dict.get(hour, 0) + 1
    return data_dict


def sortDict(got_dict):
    data_list = list(got_dict.items())
    data_list.sort()
    return data_list[:]

def print_list(got_list):
    print('\nHOUR\tREPITITION')
    for hour, count in got_list:
        print('{}\t{}'.format(hour, count))
    print()


def main():
    res_dict = getHourInDict(input('Enter the filename: '))
    res_list = sortDict(res_dict)
    print_list(res_list)


if __name__ == "__main__":
    main()
