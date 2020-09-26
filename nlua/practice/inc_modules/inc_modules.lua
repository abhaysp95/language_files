#!/usr/bin/lua5.3

-- the io table in lua is an example of module, the module in lua basically means library
-- the builtin requie function is standard way of including modules

-- function in complexity

f1 = loadfile('vec_module.lua')  -- this will laod the file, compiles as chunk and then returns as function for execute

vec = f1()  -- localize the function
print(vec)
print(vec.norm(1, 1))

f2 = loadfile('vec_module.lua')
print(f1 == f2)

print("\n--------------------\n")

-- another function in complexity
d1 = dofile('vec_module.lua')  -- similar to loadfile, except it also executes and returns the value from chunk
-- so no need to localize
print(d1)
print(d1.dist(2, 4, 0, 9))

d2 = dofile('vec_module.lua')
print(d1 == d2)  -- dofile will return different value every time

print("\n--------------------\n")

-- third function in complexity in require function
v1 = require('vec_module')
print(v1)
-- difference between require and dofile is that require caches its value, so calling again with same input will give same return value
v2 = require('vec_module')  -- this is not re-executing(which means also not recompiling the module)
print(v1 == v2)
-- final difference, is that require searches the path, in package.path string
print(package.path)
-- it's a common practice to assign require to the name of module
