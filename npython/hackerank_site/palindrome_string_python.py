#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-20
Description: entering three strings and checking if combined is palindrome or not
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-20
"""

# declaring variable <<<
str1 = input('Enter first string: ')
str2 = input('Enter second string: ')
str3 = input('Enter third string: ')
# >>>

# concatenate strings: <<<
str = str1 + str2 + str3
print(f"so string will {str}")
# >>>

# checking palindrome <<<
if str == str[::-1]:
    print(f"entered string {str} is palindrome")
else:
    print(f"entered string {str} isn't palindrome")
# >>>
