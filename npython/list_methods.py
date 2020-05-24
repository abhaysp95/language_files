#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-17
Description: Implementing list methods
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-17
"""

n = input("Enter number: ")  # taking number in string
lst = list(n)
print("Max element: ", max(lst))
print("Min element: ", min(lst))

# to add list element convert them into int
lst = [int(num) for num in n]
print("Sum: ", sum(lst))
# print("Sort ascending: ", lst.sort())
lst.sort()      # if used v = lst.sort() it will return NONE
print(lst)

lst.sort(reverse=True)
print(lst)

if 1 > 2:
    print('True')

print("Length of list is: ", len(lst))
# v=".join[str(num) for num in n]
# print(v)
