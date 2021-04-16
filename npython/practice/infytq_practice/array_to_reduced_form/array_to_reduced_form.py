#!/usr/bin/env python3

tc = int(input())

for _ in range(tc):
    arr_size = int(input())
    arr = list(map(int, input().split()))
    sorted_arr = sorted(arr)
    pos_map = dict()
    for x in range(arr_size):
        pos_map[sorted_arr[x]] = x
    for num in arr:
        print(pos_map[num], end=" ")
    print()


# not so better approach

    # new_arr = list() # start after taking arr input
    # for num in arr:
        # count = 0
        # for num2 in sorted(arr):
            # if (num == num2):
                # break
            # count += 1
        # new_arr.append(str(count))
    # print(" ".join(new_arr))
