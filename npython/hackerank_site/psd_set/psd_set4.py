#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-15
Description: concatenation of two strings is complete or not
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-15
"""


# main function <<<
def main():
    '''implementing logic in main function'''
    # count1 = int(input('Enter first count: '))
    # count2 = int(input('Enter second count: '))

    string1 = input('Enter first string: ')
    string2 = input('Enter second string: ')

    count, i = 0, 0
    for word in string1.split(' '):
        for word2 in string2.split(' '):
            setis = set(word)
            setis.update(word2)
            if len(setis) >= 26:
                count = count + 1
                print(i + 1, word + word2)
                i = i + 1

    print('count is: ', count)
# >>>


if __name__ == "__main__":
    print(main.__doc__)
    main()
