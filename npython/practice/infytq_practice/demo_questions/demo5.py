#!/usr/bin/env python3

def function(string, list1):
    num = 0  # line1
    while num != len(string):
        if len(string) % 2 == 0 or (string[num] in ['a', 'e', 'i', 'o', 'u']):
            list1.append(string[num])
        num += 1  # line 2
        function(string[num:], list1)  # line 3
        break
    return list1
print(function("Epoch", []))

# option A is correct
