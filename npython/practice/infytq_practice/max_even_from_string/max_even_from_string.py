#!/usr/bin/env python3

from itertools import permutations
import math
import re

tc = int(input())

for _ in range(tc):
    string = input()

    digits = list(set(re.findall(r'\d', string)))
    digits.sort(reverse=True)
    num = int(("".join(digits)))
    if (num - (num // 2) * 2) == 0:
        print(num)
    else:
        # if the generated num is odd, then swap the first rightmost even to
        # the last of num
        dlen = len(digits)
        got_num = False
        for x in range(dlen -1, 0, -1):
            d = int(digits[x])
            if (d - (d // 2) * 2) == 0:
                digits.remove(str(d))
                digits.append(str(d))
                got_num = True
                print("".join(digits))
                break
        if not got_num:
            print(-1)






# this works
    # num = ""
    # is_even_found = False
    # for c in string:
        # if c.isdigit():
            # if c not in num:
                # if (int(c) - (int(c) // 2) * 2) == 0:
                    # is_even_found = True
                # num += c
    # if is_even_found:
        # p = permutations(num)
        # lst = list()
        # for pair in p:
            # num = int("".join(pair))
            # if (num - (num // 2) * 2) == 0:
                # lst.append(num)
        # print(max(lst))
    # else:
        # print("-1")


https://wallpaperaccess.com/dragon-ball-universe-fighters
