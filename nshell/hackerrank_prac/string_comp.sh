#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-02-20
# Description: Every string operation
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-02-20

read -r a
read -r b
read -r n
if [ $a = $b ]; then
	echo First is equal to second
elif [ $a != $b ]; then
	echo First is not equal to second
	if [ $a \< $b ]; then
		echo First is smaller than second
	else
		echo First is larger than second
	fi
fi

