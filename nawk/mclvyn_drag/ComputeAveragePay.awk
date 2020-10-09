{ pay += $2 * $3 }
END { print NR, "Employees"
	print "total pay is ", pay
	print "average pay is ", pay / NR }
