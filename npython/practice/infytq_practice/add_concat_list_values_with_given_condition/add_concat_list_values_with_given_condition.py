#!/usr/bin/env python3

tc = int(input())

for _ in range(tc):
    digits = list(map(int, input().split(',')))
    pos5 = digits.index(5)
    pos8 = digits.index(8)
    ld = len(digits)
    sum_num = 0
    mid_num = 0
    for x in range(ld):
        if x < pos5 or (x > pos8):
            sum_num += digits[x]
        if x >= pos5 and x <= pos8:
            mid_num = mid_num * 10 + digits[x]
            print("mid_num:", mid_num)
        if x == pos8:
            try:
                pos5 = digits.index(5, pos5 + 1)
            except ValueError:
                pass
            try:
                pos8 = digits.index(8, pos8 + 1)
            except ValueError:
                pass
            print("%d, %d" % (pos5, pos8))
    print(sum_num + mid_num)
    print("----------------")
