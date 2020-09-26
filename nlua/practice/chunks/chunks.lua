#!/usr/bin/lua5.3


-- the word chunk in lua means that any block of statement/s which is/are compiled as unit
-- chunks are always treated as body of function which have two consequences
-- 1. local variables are not visible outside the chunks
-- 2. you can return values which stops the execution of chunks

-- run this file from the directory of "example_chunk.lua"

res = dofile("./example_chunk.lua")
print(res)
print("x: ", x)
print("y: ", y)


-- in lua5.2, 5.3 there's builtin function called load() which accepts a string, compiles it as a lua chunk and returns a function, and you can call to execute that chunk

f = load("print('hiii')")  -- in interpretor, this isn't run yet, just compiled
f()

--[[
this is multiline
comment in lua
--]]
