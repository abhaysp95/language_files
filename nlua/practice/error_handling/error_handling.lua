#!/usr/bin/lua5.3

-- this will give "bad argument"
--io.write(false)

-- throw custom exception error, you can use builtin error function
function f()
	error("this is custom error msg")  -- interpretor will catch and print this error msg
end
f()
