#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-02-18
# Description: pass as parameter
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: date

# read -r a
# read -r b
# read -r c
# read -r s	# for symbol
var1=$*
res=$(echo "scale=4; $*" | bc)
echo $res
# echo $*
# echo "$@" | bc	# this also works though
