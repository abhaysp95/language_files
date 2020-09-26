#!/usr/bin/lua

-- can performs assignment for multiple variables on the left to multiple
-- values on the right
a, b, c = 4, 5, 6
-- it performs by putting everything from right to stack and then assigning
-- value to left one by one(just like python do)
print("before swap: ", a, ' ', b, ' ', c)
-- it makes performing swap operation easy
a, b = b, a
print("after swap: ", a, ' ', b, ' ', c)

-- g will be nil
e, f, g = 1, 2
print(e, ' ', f, ' ', g)
-- extra value from right is thrown away
h, i = 7, 8, 9
print(h, ' ', i)
