#!/usr/bin/env python3

def selectionsort(numbers):
    c = 0
    while c < len(numbers) - 1:
        ptr = c
        d = c + 1
        while d < len(numbers):
            if numbers[ptr] > numbers[d]:
                ptr = d  # move ptr to lowest(in forward direction)
            d += 1
        if ptr != c:
            numbers[ptr], numbers[c] = numbers[c], numbers[ptr]  # swap ptr and c postion
        c += 1
    return numbers

def main():
    numbers = [8, 6, 3, 2, 4]
    num_sort = selectionsort(numbers)
    print(num_sort)

main()
