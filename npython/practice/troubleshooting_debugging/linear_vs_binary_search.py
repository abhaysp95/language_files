#!/usr/bin/env python3

'''
count number of steps in both searches
'''


def linear_search(items, key):
    '''implement linear search'''
    steps = 0
    for item in items:
        steps += 1
        if item == key:
            break
    return steps


def binary_search(items, key):
    '''implement binary search'''
    items.sort()
    steps = 1  # counting the sorting step also

    middle = len(items) // 2
    start = 0
    end = len(items) - 1
    while start < end:
        middle = (start + end) // 2
        steps += 1
        if items[middle] == key:
            break
        if key > items[middle]:
            start = middle + 1
        else:
            end = middle
        if steps > 15:
            break
    return steps


def best_search(items, key):
    steps_linear = linear_search(items, key)
    steps_binary = binary_search(items, key)
    results = f"Linear: {steps_linear} steps,"
    results += f"Binary: {steps_binary} steps."

    if steps_linear < steps_binary:
        results += "Best Search result in Linear"
    elif steps_linear > steps_binary:
        results += "Best Search result in Binary"
    else:
        results += "Result is a Tie"
    return results


print(best_search([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 1))
#Should be: Linear: 1 steps, Binary: 4 steps. Best Search is Linear.

print(best_search([10, 2, 9, 1, 7, 5, 3, 4, 6, 8], 1))
#Should be: Linear: 4 steps, Binary: 4 steps. Result is a Tie.

print(best_search([10, 9, 8, 7, 6, 5, 4, 3, 2, 1], 7))
#Should be: Linear: 4 steps, Binary: 5 steps. Best Search is Linear.

print(best_search([1, 3, 5, 7, 9, 10, 2, 4, 6, 8], 10))
#Should be: Linear: 6 steps, Binary: 5 steps. Best Search is Binary.

print(best_search([5, 1, 8, 2, 4, 10, 7, 6, 3, 9], 11))
#Should be: Linear: 10 steps, Binary: 5 steps. Best Search is Binary.
