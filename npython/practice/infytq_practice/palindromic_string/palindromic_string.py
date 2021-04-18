#!/usr/bin/env python3

def get_palindrome(num):
    sec_num = 0
    while num != 0:
        sec_num = sec_num * 10 + (num - (num // 10) * 10)
        num //= 10
    return sec_num

tc = int(input())

for _ in range(tc):
    num = int(input())

    while True:
        count = 0
        pnum = get_palindrome(num)
        if pnum == num:
            break
        else:
            count += 1
            num = int(num + pnum)
    print(len(str(num)))
