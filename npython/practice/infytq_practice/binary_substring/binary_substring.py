#!/usr/bin/env python3

count = int(input())

# def substrs(in_str, out_str):
    # if (len(in_str) == 0):
        # if (len(out_str) > 1):
            # if (out_str[0] == "1" and out_str[len(out_str) - 1] == "1"):
                # substrs.substr_list.append(out_str)
                # print(substrs.substr_list)
        # return
    # if not hasattr(substrs, "substr_list"):
        # substrs.substr_list = list()
    # out1 = out_str
    # out2 = out_str
    # out2 += in_str[0]
    # in_str = in_str[1:]
    # substrs(in_str, out1)
    # substrs(in_str, out2)

def substrs(str):
    count = 0
    for x in range(len(str)):
        for y in range(x + 1, len(str)):
            if (str[x] == '1' and str[y] == '1'):
                count += 1
    return count

def approach_I_didnot_understood(str): # why this is working
    bin_list = list(str)
    count = bin_list.count("1")
    count *= (count - 1)
    return count // 2

for _ in range(count):
    str_len = int(input())
    bin_str = input()
    # substrs(bin_str, "")
    # print(substrs.substr_list)
    # print(len(substrs.substr_list))
    # print("-----------------------")
    # substrs.substr_list.clear()
    # print(substrs(bin_str))
    print(approach_I_didnot_understood(bin_str))
