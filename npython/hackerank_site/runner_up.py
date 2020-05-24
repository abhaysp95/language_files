#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
getting second runner up
"""


def sorting(got_list):
    '''function to return no duplicate and do sorting for sec min'''
    got_list.sort(key=lambda num: num[1])

    # remove duplicates
    ncount = 0
    for count, _ in enumerate(got_list[:-1]):
        if got_list[count][1] != got_list[count + 1][1]:
            got_list[ncount] = got_list[count]
            ncount += 1
    got_list[ncount] = got_list[-1]
    got_list = got_list[:ncount + 1]

    minimum = got_list[0]
    sec_min = minimum
    for num, _ in enumerate(got_list):
        if sorted(got_list, key=lambda num: num[1]) == got_list:
            minimum = got_list[0]
            sec_min = got_list[1]
        else:
            if minimum[1] > got_list[num][1]:
                sec_min = minimum
                minimum = got_list[num]
            elif (got_list[num][1] < sec_min[1]
                  and got_list[num][1] != minimum):
                sec_min = got_list[num]
    return sec_min[1]


def main():
    '''inside main function'''
    print('First enter name and then number')
    data_list = [[input(), float(input())]
                 for _ in range(int(input()))]

    second_min = sorting(data_list[:])

    second_lowest = []

    for students in data_list:
        if second_min == students[1]:
            second_lowest.append(students[0])

    second_lowest.sort()
    for name in second_lowest:
        print(name)


if __name__ == "__main__":
    main()
