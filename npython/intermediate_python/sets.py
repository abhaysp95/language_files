# sets behave mostly like lists with the distinction that they can not contain duplicate values

some_list = ['a', 'b', 'c', 'b', 'd', 'm', 'n', 'n']

duplicates = []
for value in some_list:
    if some_list.count(value) > 1:
        if value not in duplicates:
            duplicates.append(value)
print(duplicates)

# but a simpler and more elegent solution involving sets
duplicates = set([x for x in some_list if some_list.count(x) > 1])
print(duplicates)

# sets also have few other methods. Below are some of them
## Intersection
valid = set(['yellow', 'red', 'blue', 'green', 'black'])
input_set = set(['red', 'brown'])
print(valid.intersection(input_set))

## Difference
print(valid.difference(input_set))
print(input_set.difference(valid))
print(input_set.symmetric_difference(valid))
print(valid.symmetric_difference(input_set))

# you can also create sets using
a_set = {'red', 'blue', 'green'}
print("type:", type(a_set))
print(a_set)
