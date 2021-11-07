import itertools as it
import operator
import random

def naive_grouper(inputs, n) -> list[tuple]:
    num_groups = len(inputs) // n
    return [tuple(inputs[i*n:(i + 1)*n]) for i in range(num_groups)]

nums = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]
for t in naive_grouper(nums, 2):
    print(t)

def better_grouper(inputs, n) -> zip:
    # iterator objects stored in this list are with same ID, that means if one
    # is fully exhausted, then so are others
    iters = [iter(inputs)] * n
    return zip(*iters)

# zip() stops aggregating elements once the shortest iterable passed to it is exhausted. Try zip_longest()
def grouper(input: list, n: int, fill_value = None) -> it.zip_longest:
    iters = [iter(input)] * n
    return it.zip_longest(*iters, fillvalue=fill_value)

# for x in better_grouper(range(100000000), 10):
    # pass
    # print(x)

for (x, y, z) in grouper(nums, 3):
    print((x, y, z))

# you have 3 $20 bills, 5 $10 bills, 2 $5 bills and 5 $1 bills. How many way can you make change for a $100 bill ?

# A choice of k things from a set of n things is called a 'combination'. The itertools.combinations() function takes two arguments - an iterable inputs and +ve integer n - and produces an iterator over tuples of all combinations of n elements in inputs

makes_100 = set()
bills = [20] * 3 + [10] * 5 + [5] * 2 + [1] * 5
for n in range(1, len(bills) + 1):
    for combination in it.combinations(bills, n):
        if sum(combination) == 100:
            makes_100.add(combination)
print("makes_100: ", "\n".join(list(map(str, makes_100))))

# How many ways are there to make change for a $100 bill using any number of $50,$20,$10,$5 and $1 bills ?
bills = [50, 20, 10, 5, 1]
make_100 = list()
for n in range(1, 10):
    for combination in it.combinations_with_replacement(bills, n):
        if sum(combination) == 100:
            make_100.append(combination)
print("\n".join(list(map(str, make_100))))

# Another brute_force itertools function is permutations(), which accepts a single iterable and produces all possible permutations of its elements
print(list(it.permutations(['a', 'b', 'c', 'd'], 3)))


# Evens and Odds
def evens():
    n = 0
    while True:
        yield n
        n += 2

def odds():
    n = 1
    while True:
        yield n
        n += 2

odd = odds()
print(list(next(odd) for _ in range(5)))

# now check out with itertools.count()
counter = it.count()  # two argument, it.count(start, step)
print(list(next(counter) for _ in range(5)))
# it.count() is similar to how we wrote evens() and odds() function

# so, new evens and odds will be like
even = it.count(step=2)
odd = it.count(1, 2)
print(list(next(even) for _ in range(5)))
print(list(next(odd) for _ in range(5)))  # you can also pass float and negative numbers as arguments for it.count()

# to realize the power of the infinte iterator, follow this example
print(list(zip(it.count(1), ['a', 'b', 'c', 'd'])))
# it is simple example, but you just enumerated a list without a for loop without knowing the length of the list ahead of time

def fib():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b

all_ones = it.repeat(1)  # infinite sequence of 1
all_twos = it.repeat(2)

# for a finite sequence
five_ones = it.repeat(1, 5)

alternating_ones = it.cycle([1, -1])

# it.accumulate() function takes two arguments - an iterable inputs and a binary function func, and returns as iterator over accumulated results of applying func to elements of inputs. It is roughly equivalent to following generator
def accumulate(inputs, func):
    itr = iter(inputs)
    prev = next(itr)
    for cur in itr:
        yield prev
        prev = func(prev, cur)

# print(list(accumulate([1, 2, 3, 4, 5], operator.add)))
print(list(it.accumulate([1, 2, 3, 4, 5], operator.add)))

# keep track of running minimum
print(list(it.accumulate([9, 21, 17, 5, 11, 12, 2, 6], min)))

# more complex functions can be passed to accumulate() with lambda expr
print(list(it.accumulate([1, 2, 3, 4, 5], lambda x, y: (x + y) / 2)))

# order of the arguments passed in the binary function is important too in accumulate(). First argument is always previously accumulated result and second will be the next element of input iterable
print(list(it.accumulate([1, 2, 3, 4, 5], lambda x, y: x - y)))
print(list(it.accumulate([1, 2, 3, 4, 5], lambda x, y: y - x)))

# to model a reccurence relation, you can just ignore the second
# argument of the binary function passed to accumulate(). That is,
# given values p, q, and s, lambda x, _: p * s + q will return the value
# following x in the recurrence relation defined by Si = PSi-1 + Q
# In order for accumulate() to iterate over the resulting recurrence relation, you need to pass to it an infinite sequence with the right initial value. It doesn't matter what the rest of the values in the sequence are, as long as the initial value is the initial value of the reccurence relation
def first_order(p, q, initial_value):
    """return sequence defined by S(n) = P * S(n - 1) + q"""
    return it.accumulate(it.repeat(initial_value), lambda s, _: p * s + q)

even_fo = first_order(p = 1, q = 2, initial_value = 0)
print(list(next(even_fo) for _ in range(5)))
odd_fo = first_order(1, 2, 1)
print(list(next(odd_fo) for _ in range(5)))
count_by_threes = first_order(1, 3, 0)
print(list(next(count_by_threes) for _ in range(5)))
all_twos = first_order(1, 0, 2)
print(list(next(all_twos) for _ in range(5)))
alternating_ones = first_order(-1, 0, 1)
print(list(next(alternating_ones) for _ in range(5)))

def second_order(p, q, r, initial_values):
    """Return sequence defined by S(n) = P * S(n - 1) + Q * S(n - 2) + r"""
    intermediate = it.accumulate(
            it.repeat(initial_values),
            lambda s, _ : (s[1], p * s[1] + q * s[0] + r))
    return map(lambda x: x[0], intermediate)

fibs = second_order(p = 1, q = 1, r = 0, initial_values = (0, 1))
print(list(next(fibs) for _ in range(8)))

pell = second_order(p = 2, q = 1, r = 0, initial_values = (0, 1))
print(list(next(pell) for _ in range(6)))

lucas = second_order(p = 1, q = 1, r = 0, initial_values = (2, 1))
print(list(next(lucas) for _ in range(6)))

alt_fibs = second_order(p = 1, q = 1, r = 0, initial_values = (-1, 1))
print(list(next(alt_fibs) for _ in range(6)))


# dealing a deck of cards
ranks = [ 'A', 'K', 'Q', '10', '9', '8', '7', '6', '5', '4', '3', '2', '1' ]
suits = [ 'H', 'D', 'C', 'S' ]

def cards():
    """Return a generator that yields playing cards"""
    for rank in ranks:
        for suit in suits:
            yield rank, suit

# or with generator expression
card_s = ((rank, suit) for rank in ranks for suit in suits)

# the itertools.product() function takes any number of iterables as
# arguments and returns an iterator over tuples
# print(it.product([1, 2], ['a', 'b']))
for x in it.product([1, 2], ['a', 'b']):
    print(x)
# the product() function is another "brute force" function and can lead to combinatorial explosion if you aren't careful

card_s = it.product(ranks, suits)

# putting the salt
def shuffle(deck):
    """Return iterator over shuffled deck"""
    deck = list(deck)
    random.shuffle(deck)
    return iter(tuple(deck))

card_s = shuffle(card_s)
# for x in card_s:
    # print(x)

# The random.shuffle() function uses the Fisher-Yates shuffle to shuffle a list (or any mutable sequence) in place in O(n) time. This algorithm is well-suited for shuffling cards because it produces an unbiased permutation - that is, all permutations of the iterable are equally likely to be returned by random.shuffle()

def cut(deck, n):
    """Return an iterator over a deck of cards at index `n`"""
    if n < 0:
        raise ValueError("`n` must be a non-negative integer")

    deck = list(deck)
    return iter(deck[n:] + deck[:n]) # new deck with bottom half up and top half down
# card_s = cut(card_s, 26) # cut the deck in half

# it.tee() can be used to create any number of independent iterators from a single iterable. It takes two arguments: the first is an iterable inputs, and the second is the number n of independent iterators over inputs to return (by defualt, n is set to 2). The iterators are returned in a tuple of length n
iterator1, iterator2 = it.tee([1, 2, 3, 4, 5], 2)
print(list(iterator1))
print(list(iterator1))  # exhausted
print(list(iterator2))  # working
# when a value is extracted from one iterator, that value is appended
# to the queues (FIFO queue) for the other iteratos. Thus, if one
# iterator is exhausted before the others, each remaining iterator
# will hold a copy of the entire iterable in memory
iterator1, iterator2 = it.tee([1, 2, 3, 4, 5], 2)
for _ in range(3):
    print(next(iterator1))
for _ in range(5):
    print(next(iterator2))
for _ in range(2):
    print(next(iterator1))

# The islice() function works much the same way as slicing a list or
# tuple. You pass it an iterable, a starting and stopping point, and,
# just like slicing a list, the slice returned stops at the index
# before the stopping point. You can optionally include a step value,
# as well. The biggest difference here is, of course, that islice()
# returns an iterator
# slice from index 2 to 4
print(list(it.islice('abcdefg', 2, 5)))
# slice from beginning to index 4, in steps of 2
print(list(it.islice([1, 2, 3, 4, 5], 0, 5, 2)))
# slice from index 3 to the end
print(list(it.islice(range(10), 3, None)))
# slice from begining to index 3
print(list(it.islice('abcde', 4)))
# it.islice() won't accept negative indices

# it.chain() takes any number of iterables as arguments and "chains"
# them together
print(list(it.chain("ABC", "DEF")))
print(list(it.chain([1, 2], [3, 4, 5, 6], [7, 8, 9])))

def cut_revisied(deck, n):
    """return an iterator over a deck of cards cut at index `n`"""
    # deck1, deck2 = it.tee(deck, 2)
    # top = it.islice(deck1, n)
    # bottom = it.islice(deck2, n, None)

# thought for above function: we can just work with 'deck' only, and

    top = it.islice(deck, n)
    bottom = it.islice(deck, n, None)
    return it.chain(bottom, top)
# don't need to make two iterators deck1 and deck2
card_s = cut(card_s, 26)
# print(list(card_s))

def deal(deck, num_hands = 1, hand_size = 5):
    iters = [iter(deck)] * hand_size
    # for itr in iters:
        # print(tuple(it.islice(itr, num_hands)))
    # print(tuple(zip(*(tuple(it.islice(itr, num_hands)) for itr in iters))))
    return tuple(zip(*(tuple(it.islice(itr, num_hands)) for itr in iters)))

p1_hand, p2_hand, p3_hand = deal(card_s, 3)
print(p1_hand)
print(p2_hand)
print(p3_hand)

# (('2', 'C'),)
# (('5', 'D'),)
# (('K', 'D'),)
# (('6', 'H'),)
# (('2', 'H'),)
