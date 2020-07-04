#!/usr/bin/env python

fhand = open(input('Enter file name: '), 'r')
dict_word = dict()

for line in fhand:
    words = line.split()
    if len(words) == 0:
        continue
    for word in words:
        for chr in word:
            # if not chr.isalpha():
                # continue
            # if chr in dict_word:
                # dict_word[chr] = dict_word[chr] + 1
            # else:
                # dict_word[chr] = 1
            if not chr.isalpha():
                continue
            # don't get confused if this will put alphabets with 0, it'll not
            # because every chr is already present in the word which is getting here
            dict_word[chr] = dict_word.get(chr, 0) + 1

fhand.close()
# print(dict_word)

# for key, value in dict_word.items():
# print('{}: {}'.format(key, value))

# in sorted order

for key in sorted(dict_word.keys()):
    print('{}: {}'.format(key, dict_word[key]))
