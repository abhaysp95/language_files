# print the input in reverse order
# using for delibirately here(for demonstration)

# array index in awk starts from 1
{ line[NR] = $0 }
END {
	for (i = 1; i <= NR; i = i + 1) {
		print line[i]
	}
}
