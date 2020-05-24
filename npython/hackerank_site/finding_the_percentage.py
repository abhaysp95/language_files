#!/usr/bin/env python
#     _    ____  ____
#    / \  / ___||  _ \   Abhay Shanker Pathak
#   / _ \ \___ \| |_) |  abhaysp9955@gmail.com
#  / ___ \ ___) |  __/   https://github.com/coolabhays
# /_/   \_\____/|_|

"""
average of marks obtained by students
"""


def main():
    '''inside main function'''
    count = int(input())
    student_marks = {}
    for _ in range(count):
        name, *line = input().split(' ')
        scores = list(map(float, line))
        student_marks[name] = scores
    query = input()
    sum_is = 0
    for values in student_marks[query]:
        sum_is += values
    print("{:.2f}".format(sum_is/len(student_marks[query])))


if __name__ == "__main__":
    main()
