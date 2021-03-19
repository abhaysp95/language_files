#!/usr/bin/env python3

def get_safe_position(n, k):  # get w(n, k)
    if (n == 0):
        return 0
    else:
        return ((get_safe_position(n - 1, k) + k) % n)

def main():
    n, k = [int(x) for x in input('Enter the n & k: ').split()]
    all_positions = list(range(1, n + 1))  # this is not necessary
    # the above list is used just because you can put the elements you want,
    # cause w(n) will give index not element
    interval = k - 1
    get_idx = get_safe_position(n, k)
    print(all_positions[get_idx])

main()

# logic:

# 1. why %n ?
# ans -> when you are in an index, say 1 and you are having total of 6(from
# 1-6) items in circle at that time and k is 3, now by josephus principle, then
# index 3 will be the next to go and now index 3(next number actually from
# previous circle) is current pointer with circle of 5(1, 2, 3, 5(cur_pointer),
# 6), now according to this, next pointer will be index, now next pointer will
# be index 1(0 will be executed), so we can do (3 + 3) % 5 and it'll give index
# 1, and in that way, element 2 will be the next pointer from circle of 4, it

# 2. logic ?
# ans -> say, given n = 5, k = 2, so
# (w(4, 2) + 2) % 5  --> first recursive call out
# ((w(3, 2) + 2) % 4 + 2) % 5  --> second call out
# (((w(2, 2) + 2) % 3 + 2) % 4 + 2) % 5 --> after third call out
# ((((w(1, 2) + 2) % 2 + 2) % 3 + 2) % 4 + 2) % 5 --> after fourth recursive call
# (((((w(0, 2) + 2) % 1 + 2) % 2 + 2) % 3 + 2) % 4 + 2) % 5  --> after fifth recursive call
# now w(0, 2) will give 0
# so going back
# (((((0 + 2) % 1 + 2) % 2 + 2) % 3 + 2) % 4 + 2)
# ((((2 + 2) % 2 + 2) % 3 + 2) % 4 + 2)
# (((0 + 2) % 3 + 2) % 4 + 2)
# ((2 + 2) % 4 + 2)
# (0 + 2)
# 2 --> which is index for the list of element, so for [1, 2, 3, 4, 5] for k = 2,
# safe position will be 3(from list)
