#!/usr/bin/lua5.3

--[==[function to insert a string into a given positon of another one
	insert("hello world", 7, "small") --> hello small world
]==]

function insert(s, pos, subs)
	return string.sub(s, 1, pos - 1) ..  subs .. string.sub(s, pos, -1)
end

print(insert("hello world", 1, "start: "))
print(insert("hello world", 7, "small "))

function remove(s, pos, len)
	return string.sub(s, 1, pos - 1) .. string.sub(s, pos + len, -1)
end

print(remove("hello world", 7, 4))

function ispali(str)
	return str == string.reverse(str)
end
print(ispali("step on no pets"))
print(ispali("banana"))
