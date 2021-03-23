#!/usr/bin/env python3

def quicksort(numbers, beg, end):
    print("beg: ", beg, ", end: ", end)
    if beg < end:
        pivot = beg
        i = beg
        j = end
        while i < j:
            while numbers[i] <= numbers[pivot] and i < end:
                i += 1
            while numbers[j] > numbers[pivot]:
                j -= 1
            if i < j:
                numbers[i], numbers[j] = numbers[j], numbers[i]
        numbers[pivot], numbers[j] = numbers[j], numbers[pivot]
        quicksort(numbers, beg, j - 1)
        quicksort(numbers, j + 1, end)
    return numbers

def main():
    numbers = [8, 6, 3, 2, 4]
    nums = quicksort(numbers, 0, len(numbers) - 1)
    print(nums)

main()
