# to print number of employees, just do
# { print NR }

{ pay = pay + ($2 * $3) }
END { printf("%d employees\n total pay is: %d\n average pay is: %.2f\n", NR, pay, pay / NR) }


#END { print NR, "employees"
	#print "total pay is: ", pay
	#print "average pay is: ", pay / NR }
