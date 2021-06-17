#!/usr/bin/env python3

import functools
from functools import reduce

lst = [1, 2, 3, 4, 5]

print(reduce(lambda x, y: x * y, lst))
print(reduce(lambda x, y: x * y, lst, 10))  # 10 is initializer here, so first time x will be 10 and y will be 1
