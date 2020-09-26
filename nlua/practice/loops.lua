#!/usr/bin/lua5.3

-- while loop
print("while loop")
local i = 1
while i <= 10 do
	print(i)
	i = i + 1
	-- looks like lua doesn't support compount assignment like +=
end

-- a simple for loop
print("simple for loop")
for i = 1, 5 do
	print(i)
end

-- for with step
print("for loop with step 0.5")
for i = 1, 5, 0.5 do
	print(i)
end
-- note that both the starting and ending numbers are included in for

-- lua includes break(just like other programming langs) but not continue

-- repeat until(like do-while loop)
i = 1
repeat
	print(i)
	i = i + 1
until i == 10  -- this will not include 10

-- can easily exploit repeat-until
--[[i = 10
repeat
	print(i)
	i = i + 1
until i == 10  -- this loop will run endlessely]]

-- lua5.2 introduced goto statements


-- using iterator
t = { key1 = 10,
	key2 = 20,
	key3 = 30 }

for k, v in pairs(t) do
	print(k, v)
end

-- note: tables don't store any order information about keys and we also don't have guarantees about the order of iteration

-- if you only care about keys
for k in pairs(t) do
	print(k)
end


-- if you care only about value
for _, v in pairs(t) do
	print(v)
end
-- from the above block, although you can use _ to access key, but this indicates you don't care about that thing


-- using ipairs with array
fib_arr = {1, 1, 2, 3, 5, 8}
for k, v in ipairs(fib_arr) do
	print(k, v)
end
-- to summarize, use ipairs to iterate over the array that needs to be processed in order otherwise use pairs


-- let's try something

print("\n--------------------\n")

print("printing table with ipairs")
for k, v in ipairs(t) do
	print(k, v)
end
-- printing table with ipair doesn't works

print("printing array with pairs")
for k, v in pairs(fib_arr) do
	print(k, v)
end
-- but printing array with pairs work, although I'm getting an ordered pair everytime, unlike of tables
