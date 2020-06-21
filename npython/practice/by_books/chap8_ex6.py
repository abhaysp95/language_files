#!/usr/bin/env python

num_lst = []

while True:
    num = input('Enter a number: ')
    if num == 'done':
        break
    num_lst.append(num)

print(max(num_lst))
print(min(num_lst))
print(dir(num_lst))
