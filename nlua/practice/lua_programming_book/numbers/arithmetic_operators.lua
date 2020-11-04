#!/usr/bin/lua5.3

local tolerancedig = 10
function isturnbackdig(angle)
	angle = angle % 360
	return (math.abs(angle - 180) < tolerancedig)
end

local tolerancerad = 0.17
function isturnbackrad(angle)
	angle = angle % (2 * math.pi)
	return (math.abs(angle - math.pi) < tolerancerad)
end

print(isturnbackdig(-90))
print(isturnbackrad(-math.pi))

-- there are many math functions
-- math.sin
-- math.cos
-- math.tan
-- math.log
-- math.deg
-- math.rad
-- math.max
-- math.min
-- math.tointeger,  to change a double(isn't fractional) to int, OR it with 0, like 2^53 | 0
-- etc.

function randomwithoutarg()
	math.randomseed(os.time())
	return math.random()
end

function randomwitharg(start, finish)
	math.randomseed(os.time())
	return math.floor((math.random() * finish) + start)
end

print(randomwithoutarg())
print(randomwitharg(1, 6))

-- even unbaised rounding

function round(x)
	local f = math.floor(x)
	if (x == f) or (x % 2.0 == 0.5) then
		return f
	else
		return math.floor(x + 0.5)
	end
end
print(round(2.5))
print(round(3.5))
print(round(-2.5))
print(round(-1.5))
