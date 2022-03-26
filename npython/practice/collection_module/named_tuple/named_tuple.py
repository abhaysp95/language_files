#!/usr/bin/env python3

from collections import namedtuple

# namedtuple is a middle ground between of tuple and dict

Color = namedtuple('Color', ['red', 'green', 'blue', 'black'])
white = Color(55, 155, 255, 0)
# test = Color(red=10, green=20, blue=30) # this is just to be explicit, you may give positional names but you have to provide all arguments(don't think this like sql queries)
print(white.blue)
# print(test.blue)

# from python help
Point = namedtuple('Point', ['x', 'y'])
p = Point(11, y=22)
print(p.__doc__)
print(p[0] + p[1])
print(p.y - p.x)
x, y = p
print(x, y)
d = p._asdict()
d['y'] = 200
print(d['y'])
newp = Point(**d)
print(newp)
p._replace(x = 100)
print(p.x)
