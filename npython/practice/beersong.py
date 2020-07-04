#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-17
Description: coding a beer song
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-17
"""

word = "bottles"
num = int(input('Enter the num for beer song: '))

# loop logic <<<
for beer_num in range(num, 0, -1):
    print(beer_num, word, "of beer on the wall")
    print(beer_num, word, "of beer")
    print("Take one down.\nPass it around.")

    # if else logic <<<
    if beer_num == 1:
        print("No more bottles of beer on the wall")
    else:
        new_num = beer_num - 1
        if new_num == 1:
            word = 'bottle'
        print(new_num, word, "of beer on the wall")
        # >>>
    print()
# >>>
