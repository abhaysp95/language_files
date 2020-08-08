#!/usr/bin/env python3

'''
showing random in python
'''

import random

# random floating number
value = random.random()
print(value)

# random floating number in given range
value1 = random.uniform(1, 10)
print(value1)

# randomization of a dice
value_dice = random.randint(1, 6)
print(value_dice)

# choice method picks a random value from a list of value
greetings = ["hello", 'hi', 'hey', 'howdy', 'hola']
greet = random.choice(greetings)
print(greet + ', Corey!')

# multiple choices, k is how many times we pick the random value
colors = ['Red', 'Black', 'Green', 'Blue', 'Orange']
results = random.choices(colors, k=10)
print(results)

# rollout wheel
colors_list = ['Red', 'Black', 'Green']
# weight is like, red has 18/38 chance to get selected
result_is = random.choices(colors_list, weights=[18, 18, 2], k=10)
count = 0
while 'Green' not in result_is:
    result_is = random.choices(colors_list, weights=[18, 18, 2], k=10)
    count += 1
print(result_is)
print("Count to get Green is: " + str(count))

# playing cards
deck = list(range(1, 53))
random.shuffle(deck)
print(deck)

deck2 = list(range(1, 53))
# there's no uniqueness in choices method, and we only want one card at a time(as it is)
# five_cards = random.choices(deck, k=5)
# print(five_cards)
# sample method makes sure there's only unique values
hand = random.sample(deck2, k=5)  # 5 random unique values
print(hand)
