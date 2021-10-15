from functools import reduce

# these are three functions which facilitate a functional approach to programming

## Map
# Map applies a function to all the inputs in an input_list.
# Most of the times we want to pass all the list elements to a function one-by-one and then collect the output. For instance:
items = [1, 2, 3, 4, 5]
squared = []
for i in items:
    squared.append(i * i)
# Map allows us to implement this in a much simpler and nicer way.
squared = list(map(lambda x: x ** 2, items))

def multiply(x):
    return x * x

def add(x):
    return x + x

funcs = [multiply, add]
for i in range(5):
    value = list(map(lambda x: x(i), funcs))
    print(value)

## Filter
# filter creates a list of elements for which a function returns 'true'.
less_than_zero = list(filter(lambda x: x < 0, range(-5, 5)))
print(less_than_zero)
# the filter resembles a for loop but it is a builtin function and faster

## Reduce
# reduce is a really useful function for performing some computation on a list and returning the result. It applies a rolling computation to sequential pairs of values in a list
product = 1
for num in items:
    product = product * num
# print(product)
# let's try it with reduce
product = reduce(lambda x, y: x * y, items)
print(product)
