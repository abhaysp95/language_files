#!/usr/bin/env python3

'''
why to use generators
'''

# typical
# def square_numbers(nums):
    # lst = []
    # for i in nums:
        # lst.append(i*i)
    # return lst

# my_nums = square_numbers([1, 2, 3, 4, 5])
# print(my_nums)

# with generators
# def square_numbers(nums):
    # for i in nums:
        # yield i*i;

# my_nums = square_numbers([1, 2, 3, 4, 5])
# print(my_nums)  # this is the generator, it hasn't caluclated a thing

# print(next(my_nums))  # get result one by one, not all held in memory at a time
# print(next(my_nums))
# print(next(my_nums))
# print(next(my_nums))
# print(next(my_nums))

# for num in my_nums:
    # print(num)

# write it with list comprehension
# my_nums = [x*x for x in [1, 2, 3, 4, 5]]  # returns list
my_nums = (x*x for x in [1, 2, 3, 4, 5]) # returns generator object

print(my_nums)

print(list(my_nums))  # when you convert the generator to list you loose what you gain in terms of performance

for num in my_nums:
    print(num)
