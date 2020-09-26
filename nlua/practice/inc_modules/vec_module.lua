#!/usr/bin/lua5.3

-- basic vector operation

vec = {}

vec.norm = function(x, y)
	return math.sqrt(x ^ 2 + y ^ 2)
end

vec.dist = function(x1, y1, x2, y2)
	return vec.norm((x1 - x2), (y1 - y2))  -- it doesn't matter whether you put first x1 or x2 as it'll be squared
end

return vec
