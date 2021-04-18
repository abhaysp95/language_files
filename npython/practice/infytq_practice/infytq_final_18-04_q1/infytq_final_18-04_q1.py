#!/usr/bin/env python3

l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))

sum1 = sum(l1)
sum2 = sum(l2)

oddlst = list()
evenlst = list()
outlst = list()
if sum1 != sum2:
    l1len = len(l1)
    l2len = len(l2)
    for i in l1:
        for j in l2:
            if sum1 - i + j == sum2 + i - j:
                prod = i * j
                if (prod - (prod // 2) * 2) == 0:
                    evenlst.append([i, j])
                else:
                    oddlst.append([i, j])
    evenlst.sort(key=lambda x: x[0] * x[1])
    oddlst.sort(key=lambda x: x[0] * x[1], reverse=True)
    for item in evenlst + oddlst:
        outlst.append(str(item[0]))
        outlst.append(str(item[1]))
    if len(outlst) == 0:
        print("-1".strip())
    else:
        print(",".join(outlst).strip())
else:
    print("-1".strip())
