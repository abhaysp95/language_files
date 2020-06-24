#!/usr/bin/env sh

var1=10

# while "$(echo ${var1})" [ ${var1} -ge 0 ]; do
while echo $var1
	[ $var1 -ge 0 ]  # loop stops when test command returns a zero exit status
do
	echo "inside loop"
	var1=$(( var1 - 1 ))
done
