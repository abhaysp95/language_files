#!/usr/bin/python3

class Repeater:
    def __init__(self, value):
        self.value = value

    def __iter__(self):
        return RepeaterIterator(self)

class RepeaterIterator:
    def __init__(self, source):
        self.source = source

    def __next__(self):
        return self.source.value

# repeater = Repeater("Hello")
# for item in repeater:
    # print(item)

# to dispel the "magic" of for-in loop really works, we can expand this loop into a slightly longer code snippet
# repeater = Repeater("Hello")
# iterator = repeater.__iter__()  # actual iterator object (for iteration of repeater object)
# while True:
    # item = iterator.__next__() # __next__() method from the iterator object
    # print(item)

# builtin-facade functions (e.g., len())
# repeater = Repeater("Hello")
# iterator = iter(repeater)  # invokes repeater.__iter__()
# print(next(iterator))  # invokes iterator.__next__()
# print(next(iterator))
# print(next(iterator))

class BoundedRepeater:
    def __init__(self, value, max_repeats):
        self.value = value
        self.max_repeats = max_repeats
        self.count = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.count >= self.max_repeats:
            raise StopIteration
        self.count += 1
        return self.value

# repeater = BoundedRepeater("Hello", 3)
# for item in repeater:
    # print(item)

repeater = BoundedRepeater("Hello", 3)
iterator = iter(repeater)
while True:
    try:
        item = next(iterator)
    except StopIteration:
        print("stopping")
        break
    print(item)
