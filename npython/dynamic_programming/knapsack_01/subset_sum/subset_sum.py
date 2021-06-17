#!/usr/bin/env python3

def find_matching_subset(lst, fsum, lsize):
    if fsum == 0 or lsize == 0:
        return 0
    if lst[lsize - 1] > fsum:
        return find_matching_subset(lst, fsum, lsize - 1)
    return max(lst[lsize - 1] + find_matching_subset(lst, fsum - lst[lsize - 1], lsize - 1),
            find_matching_subset(lst, fsum, lsize - 1))

lsize = int(input())
arr = list(map(int, input().split()))
target = int(input())
out = find_matching_subset(arr, target, lsize)
if out == target:
    print('True')
else:
    print('False')
