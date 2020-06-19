#!/usr/bin/env sh

if [ "$#" -eq 0 ]; then
	printf "Enter something like:\n-a -b 20 -c -- p1 p2 p3 ++ c1 c2 c3"
	echo "value should be a positive integer"
	exit 1;
fi

while [ -n "$1" ]; do
	case "$1" in
		-a) if [ "$2" -eq 0 ]; then
			echo "-a option passed, with value $2"
			shift
		else
			echo "-a option passed"
		fi;;
		-b) if [ "$2" -ge 0 ]; then
			echo "-b option passed, with value $2"
			shift
		else
			echo "-b option passed"
		fi;;
		-c) if [ "$2" = "''|*[!0-9]+" ]; then  # since this was last, so $2 was getting "--"
			# this gave warning for integer expression expected
			# this regex neglects everything except numbers from 0 to 9
			echo "-c option passed, with value $2"
			shift
		else
			echo "-c option passed"
		fi;;
		--) shift
			break;;
		*) "Option $1 is not valid option";;
	esac
	shift
done

num=0
while [ -n "$1" ]; do
	[ "$1" = "++" ] && shift && break
	num=$(( num + 1 ))
	echo "#$num: $1"
	shift
done

num=0
for param in "$@"; do
	num=$(( num + 1 ))
	echo "#$num: $param"
done
