{ i = 1
	while ( i <= $3 ) {
		print("\t%.2f\n", $1 * (1 + $2) ^ i)
		i += 1
	}
}
