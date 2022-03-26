#!/usr/bin/env python3

def get_count(num):
    if num == 1:
        return 0
    num1 = float('inf')
    num2 = float('inf')
    num3 = float('inf')
    num1 = 1 + get_count(num - 1)
    if (num - (num // 2) * 2) == 0:
        num2 = 1 + get_count(num // 2)
    if (num - (num // 3) * 3) == 0:
        num3 = 1 + get_count(num // 3)
    print(num, num1, num2, num3)
    return min(num1, num2, num3)

num = int(input())
print(get_count(num))
