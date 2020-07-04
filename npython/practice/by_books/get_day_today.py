#!/usr/bin/env python

def get_day(fname):
    file_is = open(fname, 'r')

    for line in file_is:
        if not line.rstrip().startswith('From '): continue

        words = line.split()
        print(words[2])

    file_is.close()


def main():
    get_day(input('Enter filename: '))


if __name__ == "__main__":
    main()
