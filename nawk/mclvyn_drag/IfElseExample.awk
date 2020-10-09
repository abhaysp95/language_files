$2 > 4 { n += 1; pay += ($2 * $3) }
END { if ( n > 0 )
	print n, "employees, total pay is ", pay,
		  "average pay is ", pay / n
	else
		print "no employees made more than $4 an hour"
}
