#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-02-21
# Description: Using double braces and parenthesis
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-02-21

val1=10

# evaluates more arithmatic
if (( "$val1" ** 2 > 90 )); then
	(( val2 = "$val1" ** 2 ))
	echo "The square of $val1 is $val2"
fi
