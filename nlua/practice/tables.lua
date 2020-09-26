#!/usr/bin/lua5.3

-- tables are lua's only container type
-- They are associative arrays which are key, value dictionary built on hash table


-- empty table
t = {}
t.abc = 12
-- .(dot) treats the keys as string, which means it only works for identifiers(alphanumeric,_)
print(t.abc)  -- perform lookup
print(t.def)  -- def key doesn't exist, so nil
--print(t.def.ghi)  -- lookup on nil
--print(t.abc.def)  -- or something that isn't a table will not work

-- can also lookup using []
print(t["abc"])


-- we can use arbitrary lua expression as keys for table, example
a = 12
-- number as key with help of variable
t[a] = 34
print(t.a)  -- giving nil
print(t[a])  -- giving 34
-- table as key
t[t] = 56
print(t.t)  -- giving nil
print(t[t])  -- giving 56
-- function as a value
t[1] = print
t[1]("hii")  -- prints "hii"


-- non empty table creation, key as identifiers
u = {abc = 34, def = 78}
print(u.abc)
print(u.def)
u = {pr = print}
u.pr("This is print()")
-- above syntax for setting up "pr" is not containg abc and def, so u is dereferenced from its previous address
print(u.abc)
print(u.def)

-- if you wanna use non identifiers as keys, you can use [] as notation, eg.,
u = {[34] = 56, [true] = false}
print(u[34])
print(u[true])
-- print(u[12gmail])

-- arrays in lua are as tables having keys starting from 1 and are defined as
arr = {2, 5, 7, 11}
print(arr[1], " ", arr[3])
print("size of array: ", #arr)


-- tables and arrays are only equal to true when they are indentical
