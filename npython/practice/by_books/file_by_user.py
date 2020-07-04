#!/usr/bin/env python

fname = input('Enter the file name: ')
try:
    fhand = open(fname, 'rb')
except:
    print('File %s can\'t be opened:' % fname)
    exit()
count = 0
for line in fhand:
    count = count + 1
print('There are %d lines in file' % count)

fhand.seek(0, 0)

len(fhand.readlines())

print('Position of cursor is ', fhand.tell())
fhand.close()

try:
    print('File name is %s' % fhand.name)
except:
    print('File is already closed')

ffhand = open(fname, 'r')
count = 0
for lline in ffhand:  # because line was already occupied
    if lline.startswith('for'):
        # print(type(lline))
        count = count + 1
print('Lines starting with "for" are ', count)
