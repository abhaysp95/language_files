#!/usr/bin/env python3

tc = int(input())

for _ in range(tc):
    a = input().lower()  # in any case give
    b = input().lower()
    a_count = [0] * 26
    b_count = [0] * 26
    for x in a:
        a_count[ord(x) - 97] += 1  # a, b are going to be lower case letters(although this doesn't matter for anser)

    for x in b:
        b_count[ord(x) - 97] += 1

    count = 0
    for x in range(26):
        count += abs(a_count[x] - b_count[x])
    print(count)



# not so better appraoch
# count = 0
# for x in a:
    # if x not in b:
        # a = a[1:]
        # count += 1
# for x in b:
    # if x not in a:
        # b = b[1:]
        # count += 1
# print(count)
