#!/usr/bin/lua


-- boolean types
a = true
b = false

-- doesn't uses + like java or js
print("a is: ", type(a))
print("b is: ", type(b))

-- strings
print("4.32e6")
print("0x10")

-- scientific
print(4.32e6)

-- hex
print(0x10)

-- lua5.2 and before, numbers are represented internally 64bit double by defualt
-- lua5.3 still have this type, but it can internally use either int or double
-- representation

-- in interpreter you can also use: = 1 + 2
print(1 + 2)

-- to change string to number
print("string to number: ", tonumber('2.4'))

-- lua strings are immutable
s1 = "hello"
s2 = 'hello'
-- can use both "" and '' to specify strings
print("if s1 == s2: ", s1 == s2)

print("hi \n there \\")
-- lua strings internally are arbitrary byte sequences, so 0 byte is allowed
print("\65\66\67")  -- backslash followed by number to specify arbitrary byte
print(type("\65\66\67"))  -- string type

-- escape sequences are not allowed in multiline type of string
print([[
Hello,
	This is me.
	And this is lua programming.
	]])

-- builtin tostring() function represents reasonable string representation of
-- any value
print(tostring(true))

-- nil value means "no value", undefined variables evaluate to nil, it's not any error
print(abc)

-- when you specify a variable to "nil", you undefine it and set the value to garbage collect
print("before:\n", s1, s2)
s1 = nil
print("between:\n", s1, s2)
-- you can also explicitly call the garbage collector, but not necessary as garbage collector is running automatically
collectgarbage();
print("after:\n", s1, s2)


-- functions can be assigned to variables and passed into and out of another function(first order function)
fn = function(x) return x * x end
print("passing 3: ", fn(3))


-- a userdata object is a basically a blackbox type that is used by library to wrap C level structs, like, below example from C's standard io library
f = io.open("file", 'w')
print("f is: ", type(f))


-- thread is co-routine instance


-- assignments are global by default, use "local" to make them local
local a = 7
