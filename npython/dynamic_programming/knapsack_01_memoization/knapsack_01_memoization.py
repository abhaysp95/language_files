#!/usr/bin/env python3

def knapsack_01(wtlst, vlst, bc, item):
    if item == 0 or bc == 0:
        return 0
    try:
        if knapsack_01.lookup[item][bc] != -1:
            return knapsack_01.lookup[item][bc]
    except AttributeError:
        knapsack_01.lookup = [[-1 for _ in range(bc + 1)] for _ in range(item + 1)]
    if wtlst[item - 1] > bc:
        return knapsack_01(wtlst, vlst, bc, item - 1)
    knapsack_01.lookup[item][bc] = max(vlst[item - 1] + knapsack_01(wtlst, vlst, bc - wtlst[item - 1], item - 1),
            knapsack_01(wtlst, vlst, bc, item - 1))
    return knapsack_01.lookup[item][bc]

bc = int(input())
item = int(input())
weight_lst = list(map(int, input().split()))
val_lst = list(map(int, input().split()))

# lookup = [[-1 for _ in range(bc + 1)] for _ in range(item + 1)]

print(knapsack_01(weight_lst, val_lst, bc, item))
