#!/usr/bin/env python

first_dict = {
    'a': 1,
    'b': 2
}

second_dict = {
    'x': 24,
    'y': 25,
    'z': 26
}

merged_dict = {**first_dict, **second_dict}

another_merged_dict = dict(first_dict, **second_dict)

print(merged_dict)
print(another_merged_dict)
