#!/usr/bin/env python

fhand = open(input('Enter the filename: '), 'r')

word_dict = {}

for lines in fhand:
    words = lines.split()
    for count, _ in enumerate(words):
        if count >= len(words) - 1:
            break
        if count % 2 != 0:
            continue
        word_dict[words[count]] = words[count + 1]

fhand.close()
print(word_dict)

# checking for values not keys
print('relative' in word_dict)
print('creative' in word_dict)
print('computers' in word_dict)
