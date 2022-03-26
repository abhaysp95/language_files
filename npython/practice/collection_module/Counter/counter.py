#!/usr/bin/env python3

from collections import Counter, defaultdict

c = Counter('galllad')
print(c)
print(list(c.elements()))
print(c.most_common(1))  # 1 element that is most common
print(c.most_common(2)[0][0])  # 2 elements that are most common
print(c.most_common(3))  # 3 elements that are most common
c = Counter([1, 2, 'a', 'a', 2, 'b'])
print(c)
print(list(c.elements()))
print(len(c))  # count of distinct elements
c = Counter({'a': 1, 'b': 2})
print(c)
print(list(c.elements()))
print(c.items())  # below 3 are just like dictionary, so you can iterator upon with loop
print(c.keys())
print(c.values())
c = Counter(dogs = 4, cats = 2)
print(c)
print(list(c.elements()))
print(c['dogs'])
print(c['pets'])  # unlike dict(dictionary) it'll not give error but give 0


c = Counter(a = 4, b = 2, c = 0, d = -2)
d = ['a', 'b', 'b', 'c']
c.subtract(d)  # you can also do c - d (with some difference, value le 0 will not be shown with '-', same for '+')
print(c)
c.update(d)  # c + d
print(c)
c.clear()
print(c)
d = Counter(['a', 'b', 'b', 'c'])
print(c & d)  # intersection
print(c | d)



# OrderedDict() main purpose is to remember the order in which (key, value) pairs are inserted, but since python3.7(I think) built-in dictionary class can also remember order

# defaultdict() lets you set default dict if the key you're looking(indexing) upon is not present is here
li = [1, 2, 3, 4, 5, 2, 4, 1, 3, 4, 5, 6]
# you provide data type here(and it'll use the data-type's default value, like int: 0, float: 0.0)
d = defaultdict(int)
for num in li:
    d[num] += 1  # well, this is the same thing Counter is for(to get the count as value for key(element))
print(d)
