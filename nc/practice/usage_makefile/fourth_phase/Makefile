default: file.txt.end

%.txt.end: %.txt
	cat $^ | tail -n 12 > $@
