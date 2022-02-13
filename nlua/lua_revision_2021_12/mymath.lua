mmath = {
	add = function(x, y)
		return x + y
	end
}

-- or you can put it using mmath.something

function mmath.sub(x, y)
	return x - y
end

return mmath
-- this file is now a module

-- some people don't like return <> atlast, one way to eliminate this is
-- package.loaded[...] = mmath
