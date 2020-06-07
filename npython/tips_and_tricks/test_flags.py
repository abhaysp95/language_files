#!/usr/bin/env python

x, y, z = 0, 1, 0

if x == 1 or y == 1 or z == 0:
    print('true')

if 1 in (x, y, z):
    print('true')

if x or y or z:
    print('true')

# any returns true or false for given iterator and accepts single parameter
if any((x, y, z)):
    print('true')
