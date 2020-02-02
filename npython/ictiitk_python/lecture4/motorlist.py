#!/usr/bin/env python

"""
manipulating the list
"""

companies = ['honda', 'yamaha', 'suzuki']
print(companies)

companies[0] = 'ducati'
print(companies)

# append value to the list
companies.append('bajaj')
print(companies)

# add item to list
companies.insert(0, 'tvs')
print(companies)

# remove item with del, if position is known
del companies[2]
print(companies)

# remove item with pop, let's you work with popped item behaves like pop from stack
popped_company = companies.pop()
print(companies)
print(popped_company)

companies.append('bajaj')
print(companies)
last_owned = companies.pop()
print(f"The last motorcycle I owned was a {last_owned.title()}")
last_owned = companies.pop()
print(f"The last motorcycle I owned was a {last_owned.title()}")
print(last_owned)

# remove with pop when index number is known
first_owned = companies.pop(0)
print(f"First owned motercycle was {first_owned}.")
print(companies)

# to remove an item by value
last_removed = companies.remove('ducati')
print(f"Last removed item is {last_removed}.")
