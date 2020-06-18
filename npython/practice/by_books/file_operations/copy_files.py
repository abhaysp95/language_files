#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-16
Description: copy one file to another
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-16
"""

from sys import argv
from os.path import exists


# main function <<<
def main():
    '''Program to copy from one file to another'''

    script, from_file, to_file = argv  # pylint: disable=W0632

    print(f"Hey, I'm {script}")
    print(f"Copying from {from_file} to {to_file}")

    # do these in one lines
    in_file = open(from_file)
    indata = in_file.read()

    print(f"The input file is {len(indata)} bytes long")

    # if_file = exists('''/home/raytracer/Documents/npython
    # /practice/lp3thw/file_operations/to_file.txt''')
    print(f"Does the output file exists? {exists(to_file)}")
    print('READY, hit RETURN to continue, CTRL-C to abort.')
    # even if file doesn't exists, it'll be created
    input()

    # created here, if doesn't exists
    out_file = open(to_file, 'w')
    out_file.write(indata)

    print('Alright, Data is written.')

    in_file.close()
    out_file.close()
# >>>


if __name__ == "__main__":
    print(main.__doc__)
    main()
