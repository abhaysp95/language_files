#!/usr/bin/env python3

def sample_func(var1, var2, var3, var4, *var5):
    var4 += 2
    var2 = var1 * var4
    for val in var5:
        val = val * val
    print(var1, var2, var3, var4, var5)

sample_func(0, 0, 1, 2 , 3, 4, 5)
