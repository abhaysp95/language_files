#!/usr/bin/env python

fhand = open(input('Enter the filename: '), 'r')
count = 0

for line in fhand:
    words = line.split()
    if len(words) <= 1 or words[0] != 'From':
        continue
    print(words[1])
    count = count + 1

print('There were %d lines in the file with From as the first word' % count)
