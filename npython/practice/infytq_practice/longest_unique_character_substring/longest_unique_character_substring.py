#!/usr/bin/env python3

tc = int(input())

for _ in range(tc):
    string = input()

    # given constraint, min length of substring should be 3
    lens = len(string)
    max_len = 0
    # substr_list = list()
    unique_str = ""
    for x in range(lens):
        for y in range(x + 3, lens + 1):
            substr = string[x:y]
            if len(substr) != len(set(substr)):
                break
            if max_len < len(substr):
                # substr_list.append(substr)
                max_len = len(substr)
                unique_str = substr
    # print(substr_list)
    # if len(substr_list) == 0:
    if unique_str == "":
        print(-1)
    else:
        # print("".join(list(
            # filter(lambda x: len(x) == max_len, substr_list))
            # ).strip())
        print(unique_str)
