#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-24
Description: match target sum from subsets of given set
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-24
"""

import itertools


# funtion to get subset <<<
def get_subsets(val_seq, count):
    '''get all the subsets for given sequence'''
    # (for num, _ in enumerate(range(val_seq)
    return [set(x) for num in range(1, count+1)
            for x in itertools.combinations(val_seq, num)]
# >>>


# find subsets whose sum of all elements is equal to target <<<
def is_sum_equal_to_target(val_subsets, target):
    '''getting sum for subsets'''
    sum = 0
    matched_subset = []

    # loop to get sum
    for subset in val_subsets:
        # print(subset)
        sum = 0
        for num in subset:
            # print(num)
            sum = sum + num
        # print('sum is', sum)
        if sum == target:
            matched_subset.append(subset)
    return matched_subset
# >>>


# print result subset sequence in desired format <<<
def make_seq_desired_format(got_sequence):
    for subset in got_sequence:
        for num in subset:
            print(num, end=' ')
        print()
# >>>


# main function <<<
def main():
    '''Entering in main function'''
    # prompt = '> '

    # enter number count for total elements
    # print('Enter the count value')
    count = int(input())

    # enter the elements
    val_list = []
    # print('\nEnter the elements: ')
    # for _ in range(count):
    #     val_list.append(int(input(prompt)))
    values = input()
    val_list = [int(num) for num in values.split(' ')]

    # check
    # print('Entered list is: \n', val_list)

    # enter the target value
    # print('Enter target value:\n')
    target = int(input())

    # get all the subsets
    subsets = get_subsets(val_list, count)
    # print('Subsets got is: ', subsets)

    # get all the subsets whose sum matched to target
    res_subsets = is_sum_equal_to_target(subsets, target)
    # print('All the subsets whose sum are equal to target value are:')
    # print(res_subsets)

    # values in desired format
    make_seq_desired_format(res_subsets)
# >>>


if __name__ == "__main__":
    main()
