#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-17
Description: Learn python slicing(list)
Email: abhaysp9955@gmail.com
Github: https://github.com/CoolAbhayS
Last Edited: 2020-02-17
"""

players = ['virat', 'sachin', 'dhoni', 'hardik', 'rohit']
print(players[2:])
print(players[1:3])
print(players[:3])
print(players[-3:])
print(players[-4:-1])
print(players[:-2])

print("\nHere are the first three players: ")
for player in players[:3]:      # if used [:] then it will iterate through all elemmentsg
    print(player.title())

# copy list
my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = my_foods[:]      # copies to friend_foods

my_foods.append('cannoli')
friend_foods.append('ice cream')

# exactly copies
not_same = my_foods
my_foods.append('biscuit')
not_same.append('choclate')

print("My favourite foods are: ")
print(my_foods)

print("My friend's favourite foods are: ")
print(friend_foods)

print("Not so same to me: ")
print(not_same)
