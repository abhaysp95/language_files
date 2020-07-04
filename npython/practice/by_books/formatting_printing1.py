#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-06
Description: format method
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: date
"""


# main function <<<
def main():
    '''format method usage'''
    line1 = "My name is {fname}, I'm of {age}".format(fname="Abhay", age=20)
    line2 = "My name is {0}, I'm of {1}".format('Tarun', 19)
    line3 = "My name is {}, I'm of {}.format('Ayush', 21)"
    print(line1+'\n'+line2+'\n'+line3)
# >>>


main()
print('Docstring is:'+main.__doc__)
