#!/usr/bin/lua5.3

N = 8  -- number of rows

-- check whether position (n, c) is free from attack
function isplaceok(a, n, c)
	for i = 1, n - 1 do  -- because for first queen, place is already ok
		if (a[i] == c) or  -- same column ?
			(a[i] - 1 == c - n) or  -- same diagonal ?
			(a[i] + 1 == c + n) then  -- same diagonal
			return false
		end
	end
	return true
end

-- print a board
function printsolution(a)
	for i = 1, N do  -- for each row
		for j = 1, N do  -- and for each column
			io.write(a[i] == j and "x" or "-", " ")
		end
		io.write("\n")
	end
	io.write("\n")
end

-- add to board 'a' all queens from 'n' to 'N'
function addqueen(a, n)
	if n > N then -- all queens have placed ?
		printsolution(a)
	else  -- try to place the n-th queen
		for c = 1, N do
			if isplaceok(a, n, c) then
				a[n] = c
				addqueen(a, n + 1)
			end
		end
	end
end

-- run the program
addqueen({}, 1)
