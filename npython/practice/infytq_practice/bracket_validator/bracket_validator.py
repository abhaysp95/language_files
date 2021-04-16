#!/usr/bin/env python3

from collections import deque

def validator(d):
    count = 0
    print(d)
    blst = list()
    for bracket in d:
        if bracket == '(' or bracket == '{' or bracket == '[':
            count += 1
            blst.append(bracket)
            continue
        if len(blst) == 0:
            return count + 1
        pair = blst.pop()
        if bracket == ']' and pair == '[':
            count += 1
        elif bracket == '}' and pair == '{':
            count += 1
        elif bracket == ')' and pair == '(':
            count += 1
        else:
            return count + 1
    if len(blst) == 0:
        return 0
    else:
        return count + 1

tc = int(input())

for _ in range(tc):
    d = deque(input())
    print(validator(d))




    # not exactly do what the question asks(still, it is a good validator)
    # count_small = count_mid = count_big = 0
    # prev_open_small = prev_open_mid = prev_open_big = 0
    # len_d = len(d)
    # counter = 0
    # broke_position = len(d) + 2
    # while (counter < len_d):
        # c = d.popleft()
        # if c == '(':
            # count_small += 1
            # prev_open_small = counter
        # elif c == ')':
            # count_small -= 1
        # elif c == '{':
            # count_mid += 1
            # prev_open_mid = counter
        # elif c == '}':
            # count_mid -= 1
        # elif c == '[':
            # count_big += 1
            # prev_open_big = counter
        # elif c == ']':
            # count_big -= 1
        # if count_small == -1 or count_mid == -1 or count_big == -1:
            # broke_position = min(counter + 1, broke_position)
        # counter += 1
    # if count_small > 0:
        # cause, we have to give closing ones position(they broke it)
        # broke_position = min(prev_open_small + 2, broke_position)
    # if count_mid > 0:
        # broke_position = min(prev_open_mid + 2, broke_position)
    # if count_big > 0:
        # broke_position = min(prev_open_big + 2, broke_position)
    # print(broke_position)
