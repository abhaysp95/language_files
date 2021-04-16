#!/usr/bin/env python3

tc = int(input())

for _ in range(tc):
    string = input()
    strlen = len(string)
    halflen = strlen // 2
    for i in range(halflen, 0, -1):
        prefix = string[0:i]
        suffix = string[strlen - i:strlen]
        if prefix == suffix:
            print(len(prefix))
            break




# very bad approach
# strlen = len(string)
# for idx1 in range(strlen):
    # for idx2 in range(idx1 + 1, strlen + 1):
        # temp = string[idx1:idx2]
        # print('temp:', temp)
        # for idx3 in range(idx2, strlen):
            # for idx4 in range(idx3 + 1, strlen + 1):
                # temp2 = string[idx3:idx4]
                # print('temp2:', temp2)
                # if temp == temp2:
                    # lc = min(lc, len(temp))
# print(lc)
