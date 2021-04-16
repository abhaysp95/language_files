#!/usr/bin/env python3

def get_sets(inlst, outlst, main_lst):
    if (len(inlst) == 0):
        if (len(outlst) == 3):
            main_lst.append(outlst)
        return
    out1 = outlst.copy()
    out2 = outlst.copy()
    out2.append(inlst[0])
    inlst = inlst[1:]
    get_sets(inlst, out1, main_lst)
    get_sets(inlst, out2, main_lst)

arr = list(map(int, input().split()))

out = list()
main_lst = list()
get_sets(arr, out, main_lst)
print(main_lst)

max_sum = 0
for lst in main_lst:
    ai, bi, ci = lst
    if arr.index(ai) < arr.index(bi) and arr.index(bi) < arr.index(ci):
        if ai < bi and bi < ci:
            max_sum = max(max_sum, ai + bi + ci)
print(max_sum)
