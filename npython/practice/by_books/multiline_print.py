#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-07
Description: Using different quotes for printing
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-04-07
"""


# main function <<<
def main():
    ''' more printing tricks '''
    tabby_cat = "\tI'm tabbed in"
    persian_cat = "I'm split \non a line"
    backslash_cat = "I'm \\ a \\ cat"

    fat_cat = """
    I'll do a list:
    \t* Cat food
    \t* Fishies
    \t* Catnip\n\t* Grass
    """

    print(tabby_cat)
    print(persian_cat)
    print(backslash_cat)
    print(fat_cat)
    print('This is just a line.\r1234')
    # \r works as, it puts all the characters after it
    # in begining replacing begining characters.
# >>>


print(main.__doc__)
main()
