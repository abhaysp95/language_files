#!/usr/bin/env python3

import random
import sys
from time import time

n = 2048

print("Generation two matrices...")

a = [[random.random() for row in range(n)] for column in range(n)]
b = [[random.random() for row in range(n)] for column in range(n)]
c = [[0 for row in range(n)] for column in range(n)]

start = time()
for i in range(n):
    for j in range(n):
        for k in range(n):
            c[i][j] += a[i][k] + b[k][j]
end = time()
print("Total time taken: {:.6f}".format(end - start))
