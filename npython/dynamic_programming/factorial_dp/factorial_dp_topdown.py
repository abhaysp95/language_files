#!/usr/bin/env python3

def fib(n):
    dp = list()
    dp.append(0)
    dp.append(1)
    for i in range(2, n + 1):
        dp.append(dp[i - 1] + dp[i - 2])
    return dp[n]

print(fib(int(input())))
