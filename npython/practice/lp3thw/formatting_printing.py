#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-06
Description: printing, printing
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-04-06
"""


# main function <<<
def main():
    '''using format to "format" formatter'''
    formatter = "{} {} {} {}"
    print(formatter.format(1, 2, 3, 4))
    print(formatter.format("one", "two", "three", "four"))
    print(formatter.format(True, False, False, True))
    print(formatter.format('five', 'six', 'seven', 'eight'))
    print(formatter.format(formatter, formatter, formatter, formatter))
    print(formatter.format(
        "Try your",
        "Own text here",
        "Maybe a Poem",
        "Or a song about fear"
    ))
# >>>


main()
print(main.__doc__)
