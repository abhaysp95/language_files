#!/usr/bin/env python

# read in all caps


fname = input('Enter the file name: ')
file_is = open(fname, 'r')

print('\n'.join(file_is.readlines()).upper())

file_is.seek(0, 0)
# now what exercise is saying

for line in file_is:
    print(line.upper(), end='')

file_is.close()
