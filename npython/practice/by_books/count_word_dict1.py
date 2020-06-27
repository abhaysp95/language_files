#!/usr/bin/python

# remove punctuation in pythonic way

import string

def get_dict(fname):
    '''get the dictionary full'''
    try:
        fhand = open(fname, 'r')
    except:
        print('File %s can\'t be opened' % fname)
        exit()

    dict_is = dict()
    for line in fhand:
        line = line.rstrip()
# maketrans takes 1, 2 or 3 args, if 1 it should be dict, if 2 they should be strings of equal length, if 3 then 2 strings of equal len and third those strings which are mapped to none(basically what we want to  delete)
# this works by make char to their respective ascii value
# translate takes one argument, a table which maketrans() is providing and translates it into actual string
        line = line.translate(line.maketrans('', '', string.punctuation))
        line = line.lower()
        words = line.split()
        for word in words:
            dict_is[word] = dict_is.get(word, 0) + 1
    return dict_is


def print_dict(got_dict):
    '''print dict in orderly manner'''
    for key in sorted(got_dict):
        print('{}: {}'.format(key, got_dict[key]))


def main():
    res_dict = get_dict(input('Enter the filename: '))
    print_dict(res_dict)


if __name__ == "__main__":
    main()
