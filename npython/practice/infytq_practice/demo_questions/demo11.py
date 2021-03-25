#!/usr/bin/env python3

def bubble_sort(input_list):
    num = len(input_list)
    for index1 in range(num):
        for index2 in range(0, num - index1 - 1):
            if input_list[index2] > input_list[index2 + 1]:
                input_list[index2], input_list[index2 + 1] = input_list[index2 + 1], input_list[index2]
        print("pass", index1 + 1, ":", input_list)

bubble_sort([4, 10, 2, 7, 1, 8])  # what is content of input_list after 3rd pass ?
