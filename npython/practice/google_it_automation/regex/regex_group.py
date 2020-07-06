#!/usr/bin/env python3

'''
capturing groups
'''

import re

result = re.search(r"^(\w*), (\w*)$", "Lovelace, Ada")
print(result)
print(f"Groups are: {result.groups()}")
print(result[0])
print(result[1])
print(result[2])
print('Elements are {} and {}'.format(result[2], result[1]))

def rearrange_name(name):
    # res_is = re.search(r"^(\w*), (\w*.*)$", name)
    res_is = re.search(r"^([\w]*), ([\w .-]*)", name)
    if res_is is None:
        return name
    return "{} {}".format(res_is[2], res_is[1])


print(rearrange_name("Lovelace, Ada"))
print(rearrange_name('Hopper, Grace M.'))
print(rearrange_name('Ritchie, Dennis'))


# repition of pattern
print("\nRepition of character")
print(re.search(r"[a-zA-Z]{5}", "a ghost"))
print(re.search(r"[a-zA-Z]{5}", "a scary ghost appears"))
print(re.findall(r"[a-zA-Z]{5}", "a scary ghost appears"))
# \b => matches word limit at the begining and end
# of word to indicate to give full word
print(re.findall(r"\b[a-zA-Z]{5}\b", "A scary ghost appears"))
rep_pattern = re.search(r"\b[a-zA-Z]{5}\b", "A scary ghost appears")
print("{}".format(rep_pattern.span()))
print(re.findall(r"\b\w{4,10}\b", "I really like strabbery catostrophic"))
print(re.findall(r"\b\w{4,}\b", "I really like strabbery catostrophic"))
print(re.findall(r"s\w{,20}", "I really like strabbery catostrophic"))
