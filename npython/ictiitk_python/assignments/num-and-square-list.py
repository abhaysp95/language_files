#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-02
Description: get a list of num and their square in list
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-04-02
"""

# using list comprehension <<<
num_list = [x for x in range(1, int(input('Enter the max limit to be inclueded: \n')) + 1)]
print(num_list)

# multiple table of 2
table_list = [x for x in range(2, int(input('Enter max limit of number which is divisible by 2: \n')) + 2) if x % 2 == 0]
print(table_list)

# list containg num from num_list and square from table_list
res_list = [(x, x ** 2) for x in num_list if x ** 2 in table_list]
print(res_list)
# >>>
