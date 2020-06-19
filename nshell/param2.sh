#!/usr/bin/env sh

# options and parameters

while [ -n "$1" ]; do
	case "$1" in
		-a) echo "-a option found";;
		-b) echo "-b option found";;
		-c) echo "-c option found";;
		--) shift
			break;;
		*) echo "$1 is not an option"
	esac
	shift
done

# loop iteration completed
# iteration over parameter started

# echo "$*" "$@"

num=0
while [ -n "$1" ]; do
	[ "$1" = "++" ] && shift && break
	num=$(( num + 1 ))
	echo "#${num}: $1"
	shift
done

# echo "$*" "$@"

num=0
for param in "$@"; do
	num=$(( num + 1 ))
	echo "#$num: $param"
done
