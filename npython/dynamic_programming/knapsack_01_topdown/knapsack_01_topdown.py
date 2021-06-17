#!/usr/bin/env python3

bc = int(input())
item = int(input())
wlst = list(map(int, input().split()))
vlst = list(map(int, input().split()))

lookup = [[-1 for _ in range(bc + 1)] for _ in range(item + 1)]

for i in range(item + 1):
    for j in range(bc + 1):
        if i == 0 or j == 0:
            lookup[i][j] = 0
        elif wlst[i - 1] > j:
            lookup[i][j] = lookup[i - 1][j]
        else:
            lookup[i][j] = max(vlst[i - 1] + lookup[i - 1][j - wlst[i - 1]], lookup[i - 1][j])
            # lookup[i][j] = max(vlst[i - 1] + lookup[i - 1][j - 1], lookup[i - 1][j])
print(lookup)
print(lookup[item][bc])
