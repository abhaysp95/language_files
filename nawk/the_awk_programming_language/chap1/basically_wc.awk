{
	nc = nc + length($0) + 1  # 1 is for newline char
	nw = nw + NF
}
END { print NR, "lines", nw, "words and", nc, "chars" }
