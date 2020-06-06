#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
get total earned amount of shoe
"""

from collections import Counter


def first_method():
    '''first method'''
    total_shoes = int(input())
    shoe_sizes = [int(x) for x in input().split(' ')]
    total_customer = int(input())
    updated_sizes = Counter(shoe_sizes)
    temp_demand = [input().split(' ') for _ in range(total_customer)]
    tempd_demand = [map(int, x) for x in temp_demand]
    demand = [list(x) for x in tempd_demand]

    earned = 0
    for count in range(total_customer):
        if demand[count][0] in updated_sizes.keys():
            if updated_sizes.get(demand[count][0]) > 0:
                earned += demand[count][1]
                updated_sizes[demand[count][0]] = updated_sizes.get(
                    demand[count][0]) - 1
    print(earned)


def sec_method():
    '''second method'''
    total_shoes = int(input())
    shoe_sizes = Counter(map(int, input().split()))
    total_customer = int(input())

    earned = 0
    for _ in range(total_customer):
        size, price = map(int, input().split(' '))
        if shoe_sizes[size]:
            earned += price
            shoe_sizes[size] -= 1
    print(earned)


def main():
    '''inside main function'''
    sec_method()


if __name__ == "__main__":
    main()


# demand = {}
# for _ in range(total_customer):
# key, value = input().split(' ')
# demand[key] = value
# print(key, ', ', value)
# demand = list(map(int, x) for x in demand)
# for lst in temp_demand:
# demand.append([int(y) for y in lst])
# shoe_size, price = input().split(' ')
