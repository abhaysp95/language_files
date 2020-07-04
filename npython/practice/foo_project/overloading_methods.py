#!/usr/bin/env python

class Point():
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def move(self, x, y):
        self.x += x
        self.y += y

    def __add__(self, p):
        # first parameter becomes self, and second becomes p
        return Point(self.x + p.x, self.y + p.y)

    def __sub__(self, p):
        return Point(self.x - p.x, self.y - p.y)

    def __mul__(self, p):
        return (self.x * p.x + self.y * p.y)

    def __len__(self):
        import math
        # changing to int cause len(..) do not work on float values
        return int(math.sqrt(self.x**2 + self.y**2))

    def length(self):
        import math
        return math.sqrt(self.x**2 + self.y**2)

    def __ge__(self, p):
        return self.length() >= p.length()

    def __gt__(self, p):
        return self.length() > p.length()

    def __le__(self, p):
        return self.length() < p.length()

    def __lt__(self, p):
        return self.length() <= p.length()

    def __eq__(self, p):
        # return self.length() == self.length()
        return self.x == p.x and self.y == p.y

    # checks this before returning point object
    # if __str__ not found then returns point object
    def __str__(self):
        return "(" + str(self.x) + ", " + str(self.y) + ")"


def main():
    '''inside main function'''
    p1 = Point(3, 4)
    p2 = Point(3, 2)
    p3 = Point(1, 3)
    p4 = Point(0, 1)
    p5 = p1 + p2
    p6 = p4 - p1
    p7 = p2 * p3

    print(p5, p6, p7)
    print(p1 == p2)
    print(p1 > p2)
    print(p4 <= p3)
    print(len(p3))


if __name__ == "__main__":
    main()
