#!/usr/bin/env python3

# question have said to have said to make combinations of 4 integers only
# I'm not considering the case where input list is less than 4 in length

from itertools import combinations

def get_combinations1(ilst, count):
    p = combinations(ilst, count)
    max_combinations = 0
    for pair in p:
        if sum(pair) == 0:
            max_combinations += 1
            try:
                if pair not in get_combinations1.lst:
                    get_combinations1.lst.append(pair)
            except AttributeError:
                get_combinations1.lst = list()
                get_combinations1.lst.append(pair)
    return max_combinations


# long way
def get_combinations(ilst, out):
    if len(ilst) == 0:
        if len(out) == 4:
            if sum(out) == 0:
                try:
                    get_combinations.max += 1
                except AttributeError:
                    get_combinations.max = 1
        # return get_combinations.max  # no need for return(I still have to
        # understand when to return the function's static element and when not)
        # I think, when it's primitive data type elements then you can't access
        # those elements directly outside of
        # function(function_name.element_name), but if it's something like
        # 'list' etc. you can
        return
    out1 = out.copy()
    out2 = out.copy()
    out2.append(ilst[0])
    ilst = ilst[1:]
    get_combinations(ilst, out1)
    get_combinations(ilst, out2)


lst = list(map(int, input().split(',')))
ssum = int(input())
outlst = list()
# get_combinations(lst, [])
# print(get_combinations.max)

out = get_combinations1(lst, 4)
print(out)
print(get_combinations1.lst)
