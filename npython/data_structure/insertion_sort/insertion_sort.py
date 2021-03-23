#!/usr/bin/env python3

def insertionsort(numbers):
    idx = 1
    while idx < len(numbers):
        ptr = idx
        while ptr > 0 and numbers[ptr - 1] > numbers[ptr]:
            numbers[ptr - 1], numbers[ptr] = numbers[ptr], numbers[ptr - 1]
            ptr -= 1
        idx += 1
    return numbers

def main():
    numbers = [8, 6, 3, 2, 4]
    print(insertionsort(numbers))
main()
