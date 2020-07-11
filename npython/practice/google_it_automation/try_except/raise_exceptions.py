#!/usr/bin/env python3

# exceptions are raised when errors occured at runtime,
# we can also manually raise exceptions using 'raise' keyword

def first():
    raise KeyboardInterrupt


def second():
    raise MemoryError("This is an argument")


def third():
    try:
        a = int(input('Enter a positive integer: '))
        if a < 1:
            raise ValueError("%d isn't a positive integer" % a)
        print("Entry Successful")
    except ValueError as ve:
        print(ve)

if __name__ == "__main__":
    third()
