#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-27
Description: using different_sums module
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-27
"""

# import npython.ictiitk_python.lecture18.different_sums as diff_sums
import different_sums as diff_sums

PROMPT = '> '


# main function <<<
def main():
    '''Entering in main function'''
    print("What do you want to get:")
    print('''
    1. get sum of individual
    2. get sum of squares
    3. get sum of cubes''')
    choice = input(PROMPT)
    print("You entered ", choice, " as choice")
    print("Enter the end value of range(starting from 1)")
    value = int(input(PROMPT))
    print("You entered ", value, " as value")
    if choice == '1':
        print(diff_sums.summation_num(value, diff_sums.get_identity))
    elif choice == '2':
        print(diff_sums.summation_num(value, diff_sums.get_square))
    elif choice == '3':
        print(diff_sums.summation_num(value, diff_sums.get_cube))
    else:
        print("WRONG CHOICE, enter choice in between 1\t2\t3")
# >>>


if __name__ == "__main__":
    print(main.__doc__)
    main()
