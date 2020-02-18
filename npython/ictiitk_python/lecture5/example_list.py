#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-17
Description: Solving examples
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-17
"""

for n in range(1, 20):
    print(n)

num = list(range(1, (10 ** 7) + 1))
print(num, "\t")
print("Max: ", max(num))
print("Min: ", min(num))
print("Sum: ", sum(num))

odd = list(range(1, 20, 2))
print("Odd: ")
print(odd)

divby3 = list(range(3, 31, 3))
print("Divisible by 3: ", divby3)

cubics = []
for m in range(1, 11):
    val = m ** 3
    cubics.append(val)
print("Cubes from 1 to 10: ")
print(cubics)

cubin = [value ** 3 for value in range(1, 11)]
print("Cubes from 1 to 10 by comprehension: ")
print(cubin)
print("Sum from cube of 5: ", sum(cubin[4:]))   # moves from index 4 to last, can also
# give range after : like [3:7]
