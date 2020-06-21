#!/usr/bin/env python

fhand = open('romeo.txt', 'r')

new_lst = []

for line in fhand:
    words = line.split()
    if len(words) == 0:
        continue
    for word in words:
        if word not in new_lst:
            if word.isalpha():  # no special characters
                new_lst.append(word)

print(sorted(new_lst))
fhand.close()
