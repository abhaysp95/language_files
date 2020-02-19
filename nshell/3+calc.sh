#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-02-18
# Description: Calculation using brackets
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-02-18

var1=$[1 + 5]	# in posix use $((..)) instead of $[..]
var2=$(($var1 * 2))
var3=$[$var2 * ($var1 + $var2)]
echo Result is: "$var3"

