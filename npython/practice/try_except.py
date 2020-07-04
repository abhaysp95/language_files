#!/usr/bin/env python

# in python we use except instead of catch

text = input('Username: ')
try:
    number = int(text)
    print(number)
except:
    print('Invalid Username')
