#!/usr/bin/lua5.3

-- print function takes variable number of parameters and it calles tostring()
-- on those parameters, joins them with \t character adds a \n in the end and
-- sends this all to stdout

print(1, 2, false, nil, {})
