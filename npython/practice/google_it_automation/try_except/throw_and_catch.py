#!/usr/bin/env python3


def throws():
    # exception with raise uses an instance of an exception class
    raise RuntimeError('This is the error message')


def main():
    throws()


if __name__ == "__main__":
    main()
