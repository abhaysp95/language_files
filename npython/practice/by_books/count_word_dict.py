#!/usr/bin/env python


def get_word_count(fname):
    '''getting word count for the given file'''
    fhand = open(fname, 'r')
    # dict_word = {}
    dict_word = dict()

    for line in fhand:
        words = line.split()
        if len(words) == 0:
            continue
        for word in words:
            if not word.isalpha():
                continue
            # since keys will have no values so they will be starting with 1
            # due to the +1 in get() method
            dict_word[word] = dict_word.get(word, 0) + 1
    return dict_word


def sort_print(get_dct):
    for key in sorted(get_dct.keys()):
        print('{}: {}'.format(key, get_dct[key]))


def main():
    '''main function'''
    res_dict = get_word_count(input('Enter the file name: '))
    # print('Resultant dictionary is \n {}'.format(res_dict))
    sort_print(res_dict)


if __name__ == "__main__":
    main()
