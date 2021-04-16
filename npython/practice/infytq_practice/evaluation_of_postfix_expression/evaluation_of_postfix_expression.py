#!/usr/bin/env python3

from collections import deque

def calc(op1, op2, x):
    if x == '+':
        return op1 + op2
    if x == '-':
        return op1 - op2
    if x == '*':
        return op1 * op2
    if x == '/':
        return op1 // op2
    if x == '%':
        return op1 % op2

tc = int(input())

for _ in range(tc):
    pexpr = list(input())
    ixpr = deque()
    for x in pexpr:
        if x.isnumeric():
            ixpr.append(int(x))
        else:
            op1 = ixpr.pop()
            op2 = ixpr.pop()
            ixpr.append(int(calc(op2, op1, x)))
    print(ixpr[0])
