#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-02-18
# Description: Basic calculator
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-02-18

read -r a	# this will consider backslash as input not any special character
read -r s
read -r b

res=$(echo "scale=4; $a $s $b" | bc)
echo "Result: $res"
