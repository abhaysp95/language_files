#!/usr/bin/env python

# You have x no. of 5 rupee coins and y no. of 1 rupee coins. You want to purchase an item for amount z. The shopkeeper wants you to provide exact change. You want to pay using minimum number of coins. How many 5 rupee coins and 1 rupee coins will you use? If exact change is not possible then display -1.

# Input Format

# First input : Available Rs. 1 coins
# Second Input : Available Rs. 5 notes
# Third Input : Amount to be made

# Constraints

# input valid values

# Output Format

# First Line : Rs. 1 coins needed
# Second Line : Rs. 5 notes needed

a = int(input("Enter the 1 rupee count: "))
b = int(input("Enter the 5 rupee count: "))
c = int(input("Enter the total amount you have: "))
if c > ((a*1)+(b*5)):
    print("-1")
elif c%5 == 0:
    print(c//5)
elif c%5 != 0:
    d = c%5
    print(d)
    print(c//5)
