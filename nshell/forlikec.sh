#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-03-14
# Description: Creating for loop like it is in C
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-03-14

# loop <<<
for (( a = 1; a < 10; a++ ))
do
	echo "The number is $i" # not working
done
# >>>

# multiple variables <<<
for (( a = 1, b = 10; a <= 10; a++, b-- ))
do
	printf 'Difference is %s\n' "(( $a - $b ))"
	echo "$a - $b"
done
# >>>
