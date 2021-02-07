# we'll use this while statement for calculating compound interest

{ i = 1
	print $0
	while (i <= $3) {
		# value = amount(1 + rate)^years
		printf("\t%.2f\n", $1 * (1 + $2) ^ i)
		i = i + 1
	}
}

# for loop is just like for loop in C
