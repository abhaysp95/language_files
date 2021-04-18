#!/usr/bin/env python3

def find_char1(string, c):
    offset = -1
    while True:
        offset = string.find(c, offset + 1)
        if offset == -1:
            break
        else:
            yield offset

def find_char(string, c):
    idx = -1
    while True:
        try:
            idx = string.index(c, idx + 1)
            yield idx
        except ValueError:
            break

# use either find_char or find_char1(whatever you like)

string = input()

lst = list()
for c in string:
    sbstr = ""
    for offset in find_char(string.lower(), c.lower()):
        sbstr += string[offset]
    if sbstr not in lst:
        lst.append(sbstr)
lst.sort(key=lambda x: x.lower())
print(lst)
llst = len(lst)
final_output = ""
for i in range(llst // 2):
    final_output += lst[i] + lst[llst -i - 1]
if (llst - (llst // 2) * 2) != 0:
    final_output += lst[llst // 2]
print(final_output.strip())
