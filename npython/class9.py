#!/usr/bin/env python

#Task
# Given an integer, , perform the following conditional actions:

# If n is odd, print Weird
# If n is even and in the inclusive range of 2 to 5 , print Not Weird
# If n is even and in the inclusive range of 6 to 20 , print Weird
# If n is even and greater than 20 , print Not Weird
# Input Format

# A single line containing a positive integer, .

# Constraints

# Output Format

# Print Weird if the number is weird; otherwise, print Not Weird.

a = int(input("Enter the number: "))
r = a%2
if r == 1:
    print("Weird")
elif r != 1:
    if a in range(2, 5):
        print("Not Weird")
    elif a in range(6, 21):
        print("Weird")
    elif a > 20:
        print("Not Weird")
