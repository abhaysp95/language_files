#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: date
Description: some basic file operation(about write)
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-09
"""


from sys import argv


def main():  # <<<
    '''main function, performing all operations'''
    script, filename = argv  # pylint: disable=W0632

    print(f"Hey, I'm {script}.")
    print(f"We're going to erase {filename}.")
    print("If you don't want, hit CTRL-C (^C).")
    print("If you do want, hit RETURN.")

    input("?")

    print("Opening the file...")
    target = open(filename, 'w')

    print("Now I'm going to ask you for three lines:")
    line1 = input("line 1:\n")
    line2 = input("line 2:\n")
    line3 = input("line 3:\n")

    print("I'm going to write these lines to the file.")

    target.write(line1)
    target.write("\n")
    target.write(line2)
    target.write("\n")
    target.write(line3)
    target.write("\n")

    print("Closing the file.")
    target.close()
# >>>


if __name__ == "__main__":  # <<<
    print(main.__doc__)
    main()
# >>>
