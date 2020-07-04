#!/usr/bin/env python

fname = input('Enter the file name: ')
fout = open(fname, 'a')
print(fout)

line1 = "# this is the line to enter in file\nThis is next line\n"
fout.write(line1)

line2 = "# this is second attempt\r"  # \r -> return character
fout.write(line2)

line3 = "This is\ngoing to be\tthird line"
fout.write(repr(line3))

fout.close()
