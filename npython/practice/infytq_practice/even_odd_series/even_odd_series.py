#!/usr/bin/env python3

tc = int(input())

for _ in range(tc):
    string = input()

    s = set()
    for x in string:
        if x.isalnum():
            s.add(x)
    lst = list(s)
    lst.sort(reverse=True)
    max_num = int("".join(lst))
    is_even = True
    if (max_num - (max_num // 2) * 2) != 0:
        is_even = False
        # find lowest order even num
        for i in range(len(lst) - 1, 0, -1):
            num = int(lst[i])
            if (num - (num // 2) * 2) == 0:
                lst.remove(lst[i])
                lst.append(str(num))
                is_even = True
                break
    if is_even:
        print("".join(lst).strip())
    else:
        print("-1".strip())
