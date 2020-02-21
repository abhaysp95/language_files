#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-02-20
# Description: Tells the type of trinangle
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-02-20

read -r a
read -r b
read -r c
if [ $a -eq $b ]; then
	if [ $a -eq $c ]; then
		echo EQUILATERAL
	else
		echo ISOSCELES
	fi
elif [ $a -eq $c ]; then
	if [ $a -eq $b ]; then
		echo EQUILATERAL
	else
		echo ISOSCELES
	fi
elif [ $b -eq $c ]; then
	echo ISOSCELES
else
	echo SCALANE
fi
