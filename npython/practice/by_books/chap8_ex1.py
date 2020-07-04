#!/usr/bin/env python

def chop(lst1):
    lst1.pop()
    del lst1[0]
    return None


def middle(lst2):
    chop(lst2)
    return lst2


def main():
    lst3 = [1, 3, 5, 7]
    lst4 = middle(lst3)
    print(lst4)


if __name__ == "__main__":
    main()
