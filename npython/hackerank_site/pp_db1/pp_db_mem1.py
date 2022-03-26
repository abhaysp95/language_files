#!/usr/bin/env python3

def get_count(num, dp):
    if num == 1:
        return 0
    if dp[num] != 0:
        return dp[num]
    num1 = float('inf')
    num2 = float('inf')
    num3 = float('inf')
    num1 = 1 + get_count(num - 1, dp)
    if (num2 - (num2 // 2) * 2) == 0:
        return 1 + get_count(num2 // 2, dp)
    if (num3 - (num3 // 3) * 3) == 0:
        return 1 + get_count(num3 // 3, dp)
    dp[num] = min(num1, num2, num3)
    return dp[num]


num = int(input())

lst = [int(0) for _ in range(num + 1)]

print(get_count(num, lst))
