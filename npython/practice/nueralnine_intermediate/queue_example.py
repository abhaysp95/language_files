#!/usr/bin/env python3

'''
queues in python
'''

# queues can be very helpful with threading, like once the thing is processed
# which was inside the queue is popped out and the other free thread will not
# get it

import queue


numbers = [1, 2, 3, 4, 5, 6, 7]

q1 = queue.Queue()  # this is a FIFO queue
q1.put(numbers)  # this will put the list in first place as single element

for x in numbers:
    q1.put(x)

while not q1.empty():
    print(q1.get())


q2 = queue.LifoQueue()  # this is LIFO queue
q2.put(numbers)

for x in numbers:
    q2.put(x)

while not q2.empty():
    print(q2.get())


q3 = queue.PriorityQueue()
number_priority = [
    (5, "Hello"),
    (3, "Cat"),
    (6, "Palace"),
    (1, "A"),
    (4, "Dave"),
    (7, "Shanker"),
    (2, "We")
]

# q3.put(0, number_priority)  # error: can't compare(<) int with tuple
# q3.put((0, number_priority))  # error: < not supported between instances of
# str and list
q3.put((0, ''))
for pair in number_priority:
    q3.put(pair)

while not q3.empty():
    print(q3.get())
