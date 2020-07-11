#!/usr/bin/env python3

my_list = [27, 7, 3, 9, 5]


def removeValue1(myval):
    my_list.remove(myval)
    return my_list


def removeValue2(myval):
    if myval not in my_list:
        raise ValueError(f"Value {myval} not found in list")
    my_list.remove(myval)
    return my_list


print(removeValue2(27))
# called second time to show error
print(removeValue2(27))
print(removeValue2(27))
