#!/usr/bin/env python3

from itertools import permutations

def validate(string):
    count = 0
    lst = list()
    for x in string:
        if x == '(':
            lst.append(x)
            count += 1
            continue
        if (len(lst) == 0):
            return False
        b = lst.pop()
        if b == '(' and x == ')':
            count += 1
    if len(string) == count:
        return True
    return False

# string = '((()))'
num = int(input())

string = '(' * num
string += ')' * num

lst = permutations(string, len(string))
nlst = list()
for pair in lst:
    stris = ''.join(pair)
    if validate(stris):
        if stris not in nlst:
            nlst.append(stris)

for pair in nlst:
    print(pair)
