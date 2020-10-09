# it's like doing
# $ cat file | sort -r


# $0 represents whole line in awk

{ arr[NR] = $0 }
END { i = NR
		while ( i > 0 ) {
			print arr[i]
			i -= 1
		}
	}
