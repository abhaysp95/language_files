#!/usr/bin/env python3

def decode_string(string):
    dstr = list()
    count = 0
    for x in range(len(string)):
        if not string[x].isalpha():
            inc_asc_val = ord(dstr[len(dstr) - 1]) + 1
            if (inc_asc_val > 90):
                if (inc_asc_val % 90 > 1):
                    dstr[len(dstr) - 1] = chr((inc_asc_val % 90) - 1 + 65)
            else:
                dstr[len(dstr) - 1] = chr(inc_asc_val)
            count += 1
        else:
            dstr.append(string[x])
    return "".join(dstr)

tc = int(input())

for _ in range(tc):
    stra = input()
    strb = input()
    new_stra = decode_string(stra)
    new_strb = decode_string(strb)
    if new_stra == new_strb:
        print("YES")
    else:
        print("NO")
