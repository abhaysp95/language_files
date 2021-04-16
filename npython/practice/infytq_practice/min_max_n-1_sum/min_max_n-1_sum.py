#!/usr/bin/env python3

from functools import reduce

length = int(input())
nums = list(map(int, input().split()))
# nums.sort()
# print(reduce(lambda x, y: x + y, nums[:-1]))
# print(reduce(lambda x, y: x + y, nums[1:]))

# or you can find max and min and subtract max in total to get min_sum and min from total to get max_sum

min_num = 284092309384092
max_num = -108923094092384
total_sum = 0
for num in nums:
    total_sum += num
    if (num > max_num):
        max_num = num
    if (num < min_num):
        min_num = num
print(total_sum - max_num)
print(total_sum - min_num)
