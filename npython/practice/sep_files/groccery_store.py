#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-03-26
Description: grocerry store
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-03-26
"""

# <<<
count = int(input('Enter the count: '))
a = input()
alst = a.split()
b = input()
blst = b.split()
c = input()
clst = c.split()
dlst = []

length = len(clst)

for j in range(length // 2):
    dlst.append([])

# getting into dict form
i = 0
for j in range(length // 2):
    dlst[j].append(clst[i])
    dlst[j].append(clst[i + 1])
    i = i + 2

print('dlst \n', dlst)

# converting string to int
for j in range(len(blst)):
    blst[j] = int(blst[j])

# converting string into int
num = 0
for j in dlst:
    dlst[num][1] = int(j[1])
    num = num + 1

dict_ablst = dict(zip(alst, blst))
dict_dlst = dict(dlst)
print('Shopping dict is: \n', dict_ablst)
print('Stock dict is: \n', dict_dlst)

# subtracting values
res = {key: dict_dlst[key] - dict_ablst.get(key, 0) for key in dict_dlst}
print('res is \n', res)

for k, v in res.items():
    if v < 0:
        res[k] = 0

print('Final is \n', res)

# >>>
