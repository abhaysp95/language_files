#!/usr/bin/lua5.3


-- closure is a function which refers to variables that are declared outside to itself but which are not closed,

inspect = require("inspect")

function abc(a, b, c)
	print(a, b, c)
	return 3
end

res = abc(1, 2, "hii!")
print("res: ", res)

-- to load a file in interpreter use, dofile("filename") in interpreter

-- lua function calls can accept flexible number of parameters
abc(1)
abc(1, 2, "hiii!", "hello...")

-- same case with return values
a, b, c = abc(1, 2, "hiii!", "hello...")
-- here, b and c are nil

function ret4()
	return 4, 5, 6, 7
end

-- when chaining function returns output of one function goes into anothers similarily to flexible assignment
abc(ret4())  -- here, extra return value 7 will be discarded


-- anonymous function returning empty list
print("\n------------------------\n")
g = function()
	return {}
end

print(g())  -- table: 0x<some hex>
g().abc = 10
print(g().abc)  -- nil

print(inspect(g()))

-- now this one doesn't works because, g() will return a new list everytime you will call it

lg = g()
lg.abc = 10
print(lg.abc)  -- 10

-- an empty list
t = {}
t.abc = 20
print(t.abc)  -- 20

-- for the above returned list, how to assign values to keys and print those values?

-- local function
local function hi() print("hii") end
-- local functions are useful in limiting scope when like using modules


-- let's write a closure function
function add(x)
	return function(y)
		return x + y
	end
end
add5 = add(5)
add50 = add(50)
print(add5(10))
print(add50(10))
-- important thing here is that, add5 and add50 both have their a private copy of x with different value
