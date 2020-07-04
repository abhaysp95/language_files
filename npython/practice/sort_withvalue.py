#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: sort a with dict values
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-26
"""

# variable declaration <<<
# count = int(input('Enter the number of strings: '))
nlst = []
count = 0
# >>>

# loop <<<
for _ in range(int(input('Enter the number of strings: '))):
    nlst.append(input())
# >>>

print('List is: \n', nlst)

# <<<
qlst = [x.split() for x in nlst]
print('Split list is: \n', qlst)

for i in qlst:
    qlst[count][1] = int(i[1])
    count = count + 1

# >>>

# sort and change <<<
qlst.sort(key=lambda x: x[1])
print('Sorted split list is: \n', qlst)

print('Dict is: \n', dict(qlst))
# >>>
