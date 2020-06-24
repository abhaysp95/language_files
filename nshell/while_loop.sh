#!/usr/bin/env sh

var=10
while [ $var -gt 0 ]; do
	echo "$(( (var - 1) * (var -2) ))"
	# echo "($var - 1) + ($var - 2)" | bc  # working
	# looks like bodmas is applicable
	var=$[ $var - 1 ]  # in posix this method is undefined, use $((  ))
done
