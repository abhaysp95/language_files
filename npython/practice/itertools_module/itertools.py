#!/usr/bin/env python3

import math
import itertools
from itertools import count, zip_longest, cycle, repeat, starmap, chain, islice
from itertools import permutations, combinations, product, combinations_with_replacement

# itertools.count
# counter = count()
counter = count()  # equivalent to count(firstval = 0, step = 1)
counter = count(start=5, step=10)  # can also count backward and float
# for num in counter:  # this will run infinitely
    # print(num)
print(next(counter))  # next() returns the next item from iterator
print(next(counter))
print(next(counter))
print(next(counter))
print(next(counter))
print(next(counter))
print(next(counter))
print(next(counter))
print(next(counter))
print(next(counter))
print(next(counter))

print("-----------------------------------")

# small usage, let's index the list
lst = [100, 200, 300, 400, 500]
dct = list(zip(count(), lst))
print(dct)

print("-----------------------------------")

# itertools.zip_longest
# zips up until both of the iterables is not exhausted(it'll give None for the exhausted iterable)
print(list(zip_longest(range(10), lst)))
print(list(zip_longest(range(3), lst)))

print("-----------------------------------")

# itertools.cycle
# cycles the iterable again, once it is finished
cycles = cycle([1, 2, 3])
for _ in range(6):
    print(next(cycles))  # will cycle [1, 2, 3] 2 times

print("-----------------------------------")

# itertools.repeat
# repeatition = repeat(2)  # repeats the value over and over
repeatition = repeat(2, times=3) # repeat upto only 3 times
# for _ in range(6):  # since times is given to 3, so after 3 times it'll throw StopIteration exception
    # print(next(repeatition))
# so a better way will be, then
for num in repeatition:  # only 3 times
    print(num)

print("-----------------------------------")

# another little demo of repeat
print(list(map(lambda x: x ** 2, range(10))))
# let's do this with repeat
print(list(map(pow, range(10), repeat(2))))  # map passes the rest of its arguments to the function(first argument), now it'll only iterable so 'repeat(2)' instead of just '2'

print("-----------------------------------")

# itertools.starmap
# basically similar to map, but instead of iterable, you can provide the arguments in iterable of tuple
print(list(starmap(pow, [(1, 0), (2, 1), (3, 3), (4, 5), (6, 3), (7, 9)])))

print("-----------------------------------")

# itertools.permutations
# if order of arrangement matters, use permutations
letters = ['a', 'b', 'c', 'd']
numbers = [1, 2, 3, 4]
names = ['Joey', 'Tribbiani']

pres = permutations(letters, 3)  # permutation of 2 from the list
for arrangement in pres:
    print(arrangement)

print("-----------------------------------")

# itertools.combinations
# if order doesn't matters
cres = combinations(letters, 2)
for nums in cres:
    print(nums)

print("-----------------------------------")

# itertools.product
# from above two generators(permutation, combination) you're not getting element in repeat
# let's say you want to generate all possible 4 digit codes from given list
codes = product(numbers, repeat=len(numbers))  # this is permutation with repeat(cartesian product)
for code in codes:
    print(code)

print("-----------------------------------")

# itertools.combination_with_replacement
# it's like combinations with repeatition allowed
rcomb = combinations_with_replacement(numbers, len(numbers))
for nums in rcomb:
    print(nums)

print("-----------------------------------")

# itertools.chain
# if you want to iterate over multiple iterables at a time, you can either create another iterable with all the items from all the previous iterables in it(like iterable = letters + numbers + names) or
dct = {1: 'a', 2: 'b', 3: 'c'}
tl = ([1, 2], [3, 4], [5, 6, 7])
combined = chain(letters, numbers, names, dct, tl)  # so you can have different types of iterables
for item in combined:
    print(item)

print("-----------------------------------")

# itertools.islice
# just like slicing a list but used for slicing the iterators
# result = islice(range(10), 5)  # from begining of iterator upto 9, stop at 5th index(so, first 5 item)
# result = islice(range(10), 2, 5)  # start from 2
result = islice(range(20), 2, 15, 3)  # step of 3 every time
for item in result:
    print(item)

print("-----------------------------------")

# this can be useful as we may have an iterator that is too large to put in memory and we would not want to cast it to a list to do slicing, so we could use islice here
with open('./test.log', 'r') as file:
    header = islice(file, 3)
    for line in header:
        print(line, end='')  # in this way we didn't load entire content of file in memory to do slicing
