--[[
this is a multi-line comment.
See, I wasn't lying
]]

print("Hello, ".."I'm a ".."student");

--[[
* datatypes:
- nil
- number
- string
- boolean
- table
]]

local letter_underscore  -- a simple container
print(letter_underscore)  -- nil
letter_underscore = 10 + 2.4
print(letter_underscore) -- 12.4

local fname = "first_name";
local sname = "last_name";
local name = fname .. " " .. sname;
print(name)

-- multiline strings
local description = [[
	hello World
above line has actual tab
]]
print(description)

-- boolean
local old = true  -- other is "false"
-- nil and false are both false (no)
-- so, 0 and -1 all other values are true

-- scoping
C = 20 -- global
local local_c = 10
print(C, local_c)  -- lua is also case-sensitive

_G.Hello = "Hello, there!"  -- also a global scope variable

local x = 12.4
local y = nil
print(type(x))
print(type(y))

-- little math
local str = "22"
print(type(tonumber(str)))

-- you can use +,-,*,/,^,(),%

-- math lib
print("math.pi: " .. math.pi)

math.randomseed(os.time())  -- seeding for random
print("math.random(): " .. math.random(10, 40))
--[[
	it can be just math.random() a double value between 0 and 1
	or math.random(50), end limit is 50
	or math.random(1, 10), start and end limit
]]
print("os.time(): " .. os.time())

print(math.min(10, 20, 30, 40))  -- a list
-- math.max, math.floor(), math.ceil(), math.sin(), math.cos(), math.tan()

-- strings
str = "hello, world!"  -- either use '' or "", same thing
-- there is no thing as character, all are string
print("len string: " .. #str)
local str_len = #str  -- it'll still give len
print("len string: " .. str_len)

-- concat to string
print(str .. " " .. "Let's start...")

x = 22
print("x is: " .. type(tostring(x)))

-- escape character '\'
print("hello\nworld")
-- a ',' in print is same as \t
-- \v, vertical tab
-- \\ escape a backslash

-- to uppercase
print(string.upper(str))
-- string.lower() for lowercase
-- string.len(), same as #str
-- string.sub(str, 5, 2), substring
print(string.sub(str, 5, 7))  -- 3rd arg is not len but end index

print(string.char(97))  -- ascii to char
print(string.byte('a'))  -- char to ascii

print(string.rep("hello!", 10, " - "))  -- 3rd arg is seperator for repeater

-- check more for string.format()
print(string.format("pi: %.2f\nMy age: %i", math.pi, 18))
print(string.find(str, "o, w"));  -- we'll get start and end index
print(string.match(str, "rld"));  -- if finds, then returns 2nd arg, else nil

local begin, ending = string.find(str, "o, w");
print("begin: " .. begin .. "\t" .. "end: " .. ending)
-- "end" is probably a keyword, check that

-- replace
print(string.gsub(str, "o", "!"))
-- replaces all 'o' with '!' and returns new string and number of replacements performed

-- conditional statement
local state = true;
if state then
	print("state is true")
else
	print("state is false")
end
-- >,<,==,~=,>=,<=

if state and true then
	print("passed")
end
-- and, or operators
-- you can also compare strings(==, and others)
--[[
if condition then
	something
elseif condition then
	something
else
	something
end
]]

if type(state) == "boolean" then
	print("state is boolean")
elseif type(state) == "string" then
	print("state is string")
-- else is not necessary
end

-- ternary operator
local age = 19
local old = ((age > 30) and true or false)
print("old is:", old)

-- loops
for i = 1, 10, 2 do  -- remember how you range in python
	-- i is bydefault in local scope
	-- bydefault, step = 1 in loop
	print("i: " .. i)
end
print("\n")
for i = 10, 2, -3 do
	print("i: " .. i)
end

-- you already tuple_multiplexing(I'm not sure if that's what it is called) in python
local a, b, c = 10, 20, 30  -- same thing

print("\n")
local arr = {2, 3, 4, 082, 3084, 9824, 34239}
for i = 1, #arr do
	print("i: " .. i .. "=>" .. arr[i])  -- arr in lua starts from 1
end

local peeps = 10
while peeps > 0 do
	print("People present at party")
	-- peeps -= 1  -- not supported
	peeps = peeps - 1
end

local x = 0
repeat
	print("hey there")
	x = x + 2
until x > 10
-- similar to do-while loop(one-extra iteration,
-- if you'll follow the logic of for loop)

-- user input
print("What is 10 + 5 ?")
local ans = io.read()
print(type(ans))  -- it'll be string
print("your ans: " .. ans)
if tonumber(ans) == 15 then
	print("Correct")
else
	print("Incorrect")
end

-- for input in same line, instead of print, use
--io.write("Enter you name? ")
--io.read()


-- tables
-- tables are every other data structure
-- basically in lua (a container for multiple
-- variable)
-- it is array, list, set etc.
local arr = {10, 15, 20}
print(arr)  -- probably returns address
-- print(arr + 1)  -- this is not like C

-- you can have table for different data type
local arr = {10, true, "hello world", 2.4}
print(#arr)
print("last element: " .. arr[#arr])
-- table.sort()  -- will work only on same data type table

arr = {10, 2, 42, 94, 22, 56, 82}
table.sort(arr)
for i = 1, #arr do
	io.write(arr[i] .. " ")
end
print()
arr = {"this", "that", "these", "those"}
table.sort(arr)
for i = 1, #arr do
	io.write(arr[i] .. " ")
end
print()

table.insert(arr, 3, "why")  -- second arg in insert position index
table.remove(arr, 2) -- second arg is also index(not element)
local strtable = table.concat(arr, " ")
print(strtable .. "\n")

-- multi-dimensional table
arr = {
	{1, 2, 3},
	{"this", "that"},
	{true, false}
};
for i = 1, #arr do
	for j = 1, #arr[i] do
		if type(arr[i][j]) ~= "string" then
			io.write(tostring(arr[i][j]) .. " ")
		else
			io.write(arr[i][j] .. " ")
		end
	end
	print()
end

-- functions
local function disp(age)
	age = age or 5
	-- do something
end

local function sum(num1, num2)
	return num1 + num2
end

local add10 = function(number)
	local res = 10 + number
	return number, res
end

local stored, output = add10(20)
-- you can just as well use _ (like python)
print(stored, output)

local function counter(number, end_num)
	if number == end_num then
		return
	end
	print(number)
	return counter(number + 1, end_num)
end
counter(10, 15)

-- or

local function counter1(number, end_num)
	local count = number + 1

	if(count < end_num) then
		print(count)
		return counter1(count, end_num)
	end
	return count
end

counter1(10, 15)

-- anonymous function
local function counter2()
	local count = 0

	return function()
		count = count + 1
		return count
	end
end

local x = counter2()
print("x:", x, ", x():", x())
print("x:", x())
print("x:", x())

-- variable args
local function sum(...)  -- ... is a sort of list
	local sums = 0

	-- pairs() is also a way to loop through tables
	for _, value in pairs({...}) do
		-- {...} will turn it into a table
		sums = sums + value
	end
	return sums
end
print(sum(10, 5, 9))

-- you can also do

local function sum2(...)
	for i = 1, #{...} do
		-- something
	end
end

-- coroutine
local routine_1 = coroutine.create(
	function()
		for i = 2, 20, 2 do
			print(i)

			if i / 2 == 5 then
				coroutine.yield()
			end
		end
	end
)

local routine_func = function()
	for i = 1, 20, 2 do
		print(i)
	end
end

local routine_2 = coroutine.create(routine_func)

print(coroutine.status(routine_1))
--[[
	status are:
	1. running - is running
	2. suspended - is suspended or not started
	3. normal - is active but not running
	4. dead - has finished or stopped with
]]

coroutine.resume(routine_1)
coroutine.resume(routine_2)

if coroutine.status(routine_1) == "suspended" then
	coroutine.resume(routine_1)
end

print(coroutine.status(routine_1))
print(coroutine.status(routine_2))


-- working with files
-- most basic way (io.output())
-- it'll create a file or empty already existing file(overwrite basically also)

io.output("tempfile.txt")  -- this file selected
io.write("new file with x: " .. x() .. "\n")  -- will write to above file
io.close()

-- read the file
--io.input("tempfile.txt")
--local file = io.read(5)
--local file = io.read("*number")  -- returns nil ?
-- there are also "*line", "*all" and others
-- io.close() -- here it says attempt to read a closed file
--print(file + 10)
--io.close()

local file = io.open("tempfile.txt", "w")
--[[
other modes are:
r - read mode
w - write mode
a - append mode
r+ - update mode (previous data preserved)
w+ - update mode (previous data erased)
a+ - append update mode (previous data preserved, writing only allowed at end of file)
rb - read mode (binary)
wb - write mode (binary)
ab - append mode (binary)
r+b and others (with binary)
]]
file:write("your name is something")
print(file)
local reads = file:read("*all")
print(reads)  -- still returning nil
file:close()


-- os module
print(os.time()) -- seconds since epoch
local past = os.time( {
	year = 2000,
	month = 10,
	day = 1,
	hour = 13,
	min = 20,
	sec = 10
})
print(os.time() - past)
-- or
print(os.difftime(os.time(), past))
print(os.date())

-- env vars
print(os.getenv("R_LIBS"))
os.rename("tempfile.txt", "newtemp.txt")
-- there are
-- os.remove()
-- os.execute(command)
-- print(os.execute("whoami"))  -- pastes terminal output in terminal
-- and returns if command succeeded (boolean) and exit status code)
local cmd_stat, stat_str, exit_code = os.execute("whoami")
print(cmd_stat, stat_str, exit_code)

-- timer
local start = os.clock()
for i = 1, 10^5 do
	local x = 10
end
print(os.clock() - start)
-- os.exit()

-- custom module
local mmth = require("mymath")
print(mmth.add(10, 20))
print(mmth.sub(10, 20))

-- OOPs
local t = {
	name = "somename",
	age = 30,
	friends = {"f1", "f2"}
}
-- this itself can be considered a type of object
print(t.name)

local function Pet(name)
	name = name or "Luis"
	return {
		name = name,
		feeling = "hungry",
		feed = function(self)
			print(name .. " is fed")
			self.feeling = "full"
		end
	}
end

local cat = Pet("kitty")  -- cat is working like a object now
local dog = Pet()
print(cat.name)
print(dog.name)
if cat.feeling == "hungry" then
	cat:feed()
	print(cat.feeling)
end

-- inheritance (like feature)
local function Dog(name, breed)
	local dog = Pet(name)

	dog.bread = bread
	dog.loyality = 0

	dog.is_loyal = function(self)
		return self.loyality >= 10
	end

	-- overriding
	dog.feed = function(self)
		print(name .. " is fed now")
		self.loyality = self.loyality + 5
	end

	dog.bark = function(self)
		print("Woof woof...")
	end

	return dog
end

local l = Dog("max", "german-shephard")
print(l:is_loyal())
l:feed()
l:feed()
print(l:is_loyal())


-- metamethods
local metatable = {
	__add = function (x, y)
		return x.num + y.num
	end,
	-- __add is for '+'

	__sub = function(x, y)
		return x.num - y.num
	end
}

local tbl1 = { num = 10 }
local tbl2 = { num = 50, str = "this" }

setmetatable(tbl1, metatable) -- sets the metatable for the given table, the function itself returns table

local ans = tbl1 + tbl2
print(ans)

--[[
	__add = +
	__sub = -
	__mul = *
	__div = /
	__mod = %
	__pow = ^
	__concat = ...
	__len = #
	__lt = <
	__le = <=
	__eq = ==
]]
