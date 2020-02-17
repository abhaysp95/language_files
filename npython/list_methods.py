#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-17
Description: Implementing list methods
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-17
"""

n = input("Enter number: ") # taking number in string
lst = list(n)
print("Max element: ", max(lst))
print("Min element: ", min(lst))

# to add list element convert them into int
lst2 = [int(num) for num in n]
print("Sum: ", sum(lst2))
# print("Sort ascending: ", lst.sort())
v = lst.sort()
print(v)
