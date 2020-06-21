#!/usr/bin/env python

fhand = open('mbox-short.txt', 'r')

for line in fhand:
    word = line.split()
    if len(word) <=2 or word[0] != 'From':
        continue
    print(word[2])
fhand.close()
