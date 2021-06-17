#!/usr/bin/env python3

from collections import deque

d = deque("hello")
d.append(1)
d.appendleft(2)
print(d)
d.pop()
d.popleft()
print(d)
d.extend("this")  # takes any iterator
d.extendleft([1, 2, 3])
print(d)
nd = deque()
nd.extend(d)
print(nd)
d.extendleft(["add", "string"])
print(d)
d.rotate(-3)
print(d)
d.rotate(5)
print(d)
print(len(d))

snd = deque(d, maxlen=12)
print(snd)
snd.append([1, 2])
print(snd)
print(snd.maxlen)
snd.reverse()
print(snd)
# snd.maxlen = 20  # not mutable
