#!/usr/bin/env python3

row, col = list(map(int, input().split()))

matrix = [[int(x) for x in input().split()] for _ in range(row)]

def check_condition(lst):
    for i in lst:
        isum = 0
        temp = i
        while temp != 0:
            isum = isum + (temp - (temp // 10) * 10)
            temp //= 10
        if (i - (i // isum) * isum) != 0:
            return False
    return True

for i in range(row - 1):
    for j in range(col - 1):
        lst = list()
        lst.append(matrix[i][j])
        lst.append(matrix[i][j + 1])
        lst.append(matrix[i + 1][j])
        lst.append(matrix[i + 1][j + 1])
        if check_condition(lst):
            print("%d %d\n%d %d" % (lst[0], lst[1], lst[2], lst[3]))
            print("-------------------------")
