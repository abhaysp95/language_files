#!/usr/bin/env python3

from collections import defaultdict

def sort_function(x, y):
    if len(x) < len(y):
        return True

instr = input()

outarr = list()

lens = len(instr)

for x in range(lens):
    for y in range(x+1, lens+1):
        substr = instr[x:y]
        dd = defaultdict(int)
        for c in substr:
            dd[c] += 1
        all_multiple_2 = True
        for key, value in dd.items():
            if (value - (value // 2) * 2) != 0:
                all_multiple_2 = False
                break
        if all_multiple_2:
            if substr not in outarr:
                outarr.append(substr)
if len(outarr) != 0:
    outarr.sort()
    outarr.sort(key=len)
    print(",".join(outarr).strip())
else:
    print("-1".strip())
