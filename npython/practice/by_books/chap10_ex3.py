#!/usr/bin/env python

"""
print letter frequencies from given file
"""

import string


def getLettersInDict(file_name):
    '''put letters and its frequencies in dictionary'''
    try:
        file_handler = open(file_name, 'r')
    except:
        print('File %s is not present' % file_name)

    letter_dict = dict()

    letter_count = 0
    for line in file_handler:
        if len(line.split()) == 0:
            continue
        line = line.rstrip()
        line = line.translate(line.maketrans('', '', string.punctuation))
        line = line.translate(line.maketrans('', '', string.digits))
        line = line.lower()

        words = line.split()
        for word in words:
            for letter in word:
                letter_count += 1
                letter_dict[letter] = letter_dict.get(letter, 0) + 1

    return letter_dict, letter_count


def sortAndPrint(got_dict, lcount):
    letter_list = list(got_dict.items())
    letter_list.sort()  # sorted alphabetically
    lcount = sum(letter_list[1])

    for letter, count in letter_list:
        # {[arg_index]:[width][.precision][type]}
        # you can also use" '%.3f' % value " in place of this
        print("{0}{1:10.3f}%".format(letter, (count / lcount) * 100))


def main():
    res_dict, lcount = getLettersInDict(input('Enter the file name: '))
    sortAndPrint(res_dict, lcount)


if __name__ == "__main__":
    main()
