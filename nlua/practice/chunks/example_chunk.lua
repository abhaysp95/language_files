#!/usr/bin/lua5.3

-- this file is treated as a chunk by the "chunks.lua" file

local x = 3
-- locals are visible within same chunk
y = 2; print(x + y)
-- ; is optional line seperator in lua
return 'w00t'
