#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-27
Description: print dict items which have both duplicate keys and values
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-27
"""

# variable declaration <<<
count = int(input('Enter the count: '))
alst = []
blst = []
# >>>

# taking input and setting up <<<
for _ in range(count):
    alst.append([])

for i in range(count):
    alst[i].append(input())
print('alst is \n', alst)

# finding duplicate and getting into another list
for i in alst:
    if alst.count(i) > 1:
        if i not in blst:
            blst.append(i)
print('blst is \n', blst)

# spliting blst
blst = [x.split() for i in range(len(blst)) for x in blst[i]]
print('second time blst is \n', blst)

# making in int
for i in range(len(blst)):
    blst[i][1] = int(blst[i][1])
print('third time blst is \n', blst)
# >>>

# duplicates in dictionary <<<
if len(blst) > 0:
    print('duplicate dictionary is \n', dict(blst))
else:
    print('No duplicate element')
# >>>
