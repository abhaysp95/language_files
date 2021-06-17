#!/usr/bin/env python3

def knapsack_01(wl, vl, bw, ic):
    if (bw == 0 or ic == 0):
        return 0
    if wl[ic - 1] > bw:
        return knapsack_01(wl, vl, bw, ic - 1)
    return max(vl[ic - 1] + knapsack_01(wl, vl, bw - wl[ic - 1], ic - 1), knapsack_01(wl, vl, bw, ic - 1))

bag_capacity = int(input())
item_count = int(input())
weight_list = list(map(int, input().split()))
item_list = list(map(int, input().split()))
print(knapsack_01(weight_list, item_list, bag_capacity, item_count))
