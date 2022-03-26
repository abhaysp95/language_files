#!/usr/bin/env python3

li = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 ]

def isOdd(x):
    return x % 2 != 0

def square(x):
    return x ** x

# map: takes function and iterator as its two arguments
newlist = list(map(square, li))
print(newlist)
newlist = list(map(lambda x: x ** x, li))  # doing samething with lambda
print(newlist)

# filter: also takes two arguments, function and iterator but only gives(performs operation on those elements for which function gives True)
boolList = list(filter(isOdd, li))
print(boolList)  # prints only odd numbers

# now get the square of number which are odd
oddsquare = list(map(square, filter(isOdd, li)))
print(oddsquare)
# get square of numbers which are not odd
# evensquare = list(map(square, filter(not isOdd, li)))  # this doesn't work
# print(evensquare)

# so, doing with lambda function
oddsquare = list(map(lambda x: x ** x, filter(lambda x: x % 2 != 0, li)))
print(oddsquare)
evensquare = list(map(lambda x: x ** x, filter(lambda x: x % 2 == 0, li)))
print(evensquare)

# little more detail on lambda(anonymous function)
def func(x):
    return x + 5

func2 = lambda x: (x + 4)/5  # anything which can be fitted in one line is possible to be returned from lambda
print(func(10))
print(func2(11))

# lambda is most beneficial with map and filter

def func3(x):
    x += 10
    return func2(x)
print(func3(12))
