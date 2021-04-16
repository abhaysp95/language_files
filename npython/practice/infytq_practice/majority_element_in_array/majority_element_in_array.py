#!/usr/bin/env python3

tc = int(input())

for _ in range(tc):
    arr_size = int(input())
    count_map = dict()
    arr = list(map(int, input().split()))
    for num in arr:
        if num in count_map.keys():
            count_map[num] += 1
        else:
            count_map[num] = 1
    majority_element = -1
    for key, value in count_map.items():
        if value > arr_size // 2:
            majority_element = key
    print(majority_element)

# or you can have a very long list with every positional element to 0 and
# increment the indexed value for the element of array and get max with every
# iteration of loop in that time, after that get back the index of the max
# element from the array and that'll be the answer
