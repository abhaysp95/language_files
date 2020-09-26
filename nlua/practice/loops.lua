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
