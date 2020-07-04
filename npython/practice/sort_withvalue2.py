#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-27
Description: Sort values of dict
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-27
"""

# variable declaration <<<
main_dict = {}
alst = []
qt = []
vlst = []
count = int(input('Enter the count: '))
# >>>

# loop and settings <<<
# taking input
for _ in range(count):
    alst.append(input())
print('alst is \n', alst)

# entering key in a list
for i in range(count):
    for j in alst[i].split():
        qt.append(j)
        break
print('qt is \n', qt)

# preparing a list for values
for _ in range(count):
    vlst.append([])

# inserting values in vlst
num = 0
k = 0
for i in range(count):
    num = 0
    for j in alst[i].split():
        if num != 0:
            vlst[k].append(int(j))
        num = num + 1
    k = k + 1
print('vlst is: \n', vlst)

# sorting values
for i in range(count):
    vlst[i].sort()

# inserting keys, values and making dict
i = 0
for key in qt:
    main_dict.setdefault(key, [])
    for j in vlst[i]:
        main_dict[key].append(j)
    i = i + 1
# you can also use dict(zip(qt, vlst))

print('Main dict is: \n', main_dict)
# >>>
