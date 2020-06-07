#!/usr/bin/env python

import operator

dict_is = {
    'first': 345,
    'second': 129,
    'third': 248,
    'fourth': 239,
    'five': 193
}

print(dict_is)
print(sorted(dict_is.items(), key=lambda x: x[1]))
print(dict_is)
print(sorted(dict_is.items(), key=lambda x: x[0]))

print(sorted(dict_is.items(), key=operator.itemgetter(1)))
print(sorted(dict_is.items(), key=operator.itemgetter(0)))
