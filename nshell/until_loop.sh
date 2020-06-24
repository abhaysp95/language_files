#!/usr/bin/env sh

var1=100
until [ $var1 -eq 0 ]; do
	echo "$var1"
	var1=$(( var1 - 25 ))
done

var1=100
while [ $var1 -gt 0 ]; do
	echo "$var1"
	var1=$(( var1 - 25 ))
done
