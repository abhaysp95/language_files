#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-10
Description: another file with write operation example
Email: abhaysp9955@gmail.com
Last Edit: date
"""

from sys import argv


# main <<<
def main():
    '''Entering in main function'''
    script, filename = argv  # pylint: disable=W0632
    print(f"Hello, I'm {script}")
    print(f"Here is your opened file {filename}")

    txt = open(filename)

    print("Reading your file\n")
    print(txt.read())
    print(txt.readline())

    print("""{} is going to be appended.
    If you don't want it, press CTRL-C,
    else press RETURN""".format(filename))

    print("?")
    # use w for write mode, it'll delete the previous content
    print("Opening filename in append mode")
    txt = open(filename, 'a')

    print('Enter the count of how many lines you want to write.')

    write_lst = []
    for _ in range(int(input())):
        write_lst.append(input())

    print('I\'m going to write these lines in file')
    for line in write_lst:
        txt.write(line)
        txt.write('\n')

    print(f"So, you wrote these things in {filename}:")
    txt = open(filename)
    print()
    print(txt.read())

    print('Closing the file')
    txt.close()
# >>>


# calling main <<<
print(main.__doc__)
main()
# >>>
