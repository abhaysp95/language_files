#!/usr/bin/env python3

def get_fibonacci(num):
    if (num == 1 or num == 0):
        return num
    try:
        if get_fibonacci.mem_list[num] != 0:
            return get_fibonacci.mem_list[num]
    except AttributeError:
        get_fibonacci.mem_list = [0] * (num + 1)
    get_fibonacci.mem_list[num] = get_fibonacci(num - 1) + get_fibonacci(num - 2)
    return get_fibonacci.mem_list[num]

num = int(input())
get_fibonacci(num)
print(get_fibonacci.mem_list[num])



# having static this way is not good, cause it'll do condition checking every time(use error-handling instead)
    # if not hasattr(get_fibonacci, "mem_list"):
        # get_fibonacci.mem_list = [0] * (num + 1)
