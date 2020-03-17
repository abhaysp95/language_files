#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-17
Description: Find whether entered string is palindrome or not
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-17
"""

# logic <<<
my_str = input('Enter the string: ')

# my_lst = list(my_str)
# rev_lst = []

# for i in range(len(my_lst)):
#     rev_lst.append(my_lst[i])

# if my_lst == rev_lst:
#     print("String is palindrome")
# else:
#     print("String is not palindrome")
# >>>

# another logic <<<
rev_str = my_str[::-1]
print(rev_str)
if my_str == rev_str:
    print("String is palindrome")
else:
    print("String is not palindrome")
# >>>
