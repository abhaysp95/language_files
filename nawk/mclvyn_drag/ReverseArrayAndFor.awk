{ arr[NR] = $0 }
END { i = NR
		for ( i = NR; i > 0; i -= 1 ){
			print arr[i]
		}
	}
