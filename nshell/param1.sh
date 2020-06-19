#!/usr/bin/env sh

if [ "$#" -eq 0 ]; then
	printf "Enter something like\n-a -b -c -- p1 p2 p3\n"
	exit 1;
fi

echo "$@"  # array
echo "$#"  # number
echo "$*"  # concatenate

shift

echo "$@"
echo "$#"
echo "$*"

shift

echo "$@"
echo "$#"
echo "$*"
