#!/usr/bin/lua

-- usual arithmetic operators
print(1 + 2 - 3 * 4 / 5 ^ 8 % 3)  -- 2.99996928, follow BODMAS, ^ will perform first, % is performed at last(?)
print((1 + 2 - 3 * 4 / 5 ^ 8) % 3)  -- is same to above
print(((1 + 2) - (((3 * 4) / (5 ^ 8)) % 3)))  -- same with better scoping of operators
print(1 + 4 / 5 ^ 8 % 3 - 2 * 3)  -- -4.99998976
print((1 + 4 / 5 ^ 8) % 3 - (2 * 3))  -- same to above
print(((1 + (4 / (5 ^ 8)) % 3) - (2 * 3)))  -- so it's left to right with following operator precedence
-- does, is it like "left % a <operator> right", first left will be solved then left % a, and then the right portion

print("--------------------------")

-- division is performed as a floating point operation, even if the inputs are
-- integer value
print(3/5)  -- 0.6
print(2/3)  -- 0.666666666666667
print(type(3/5))  -- number

print("--------------------------")

-- modulus operator also works with float and negative numbers in lua
print(1.1 % 0.3)  -- 0.2
print(11 % 3)  -- technique same as above

print(1.1 % -0.3)  -- -0.1
print((1.1 % 0.3) - 0.3)  -- same as above

print(11 % -3)  -- -1
print((11 % 3) - 3)  -- basically this is the technique for negative

print("--------------------------")

-- also reminding, these 4 all are different
print("a: ", 1.1 % -0.3)  -- -0.1
print("b: ", -1.1 % 0.3)  -- 0.1
print("c: ", -(1.1 % 0.3))  -- -0.2
print("d: ", -1.1 % -0.3)  -- -0.2

print("--------------------------")
print(-1.1 % 0.3)  -- 0.1
print(0.3 - (1.1 % 0.3))  -- this is same as above

print("--------------------------")
print(-1.1 % -0.3)
print((0.3 - (1.1 % 0.3)) - 0.3)

-- so following conclusion can be derived for modulus:
-- for a % b, where 0 < a,b < 1 and are integers, result will same after evening out the points for "a" and "b"
-- for a % b, where b < 0, result is equal to, ((a % |b|) - |b|)
-- for a % b, where, a < 0, result is equalt to (b - (|a| % b))
-- for a % b, where a, b < 0, result is equal to ((|b| - (|a| % |b|)) - |b|), or you can also just use do (-(|a| % |b|)) and result will be same

print("--------------------------")

-- get string length with # operator
s1 = "Hello there!"
print(#s1)

print("--------------------------")

-- lua has somewhat similar conditional operators
print(2 ~= 3)  -- not equals to
-- print(2 != 3) this doesn't works here
-- print(2 <> 3) this also
print(2 == "2")
print('abc' < 'abd')  -- lexographical according to current local

print("--------------------------")

print('abc' .. 'def')  -- .. is used for string concatenation
print('abc' .. 456)  -- this did implicit conversion of int to string I think
-- print('abc' .. true)  will not work
-- so, we can only concatenate string and number with .. to make the string


-- multiline string
print([[
level one mulitline ]])

print([=[
level one mulitline
]=])

-- find out how to escape [] when using multiline print
print([====[
	This is level 4 multiline.
	Shown as \[====[]====\]
	Although we can use more than 4 lines in this,
	but it's good to use four lines only ]====])

print("--------------------------")

-- nil and false are the only falsy value in lua, that means 0 is considered true
print(not nil)  -- nil is false, so this is true
print(not not nil)  -- this is false

print(true and print('hi'))  -- nil cause of print inside print
print(true and 'hi')  -- prints hi
print(false and print('hi'))  -- gives false only

-- For bitwise operators, lua5.2 have bit32 module which offers them as functions, but lua5.3 adds these operators to the language itself
