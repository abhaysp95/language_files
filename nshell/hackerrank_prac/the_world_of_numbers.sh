#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-02-19
# Description: nothing
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-02-19

read -r a
read -r b
# if ([ "$a" -ge -100 ] && [ "$a" -le  100 ]) || ([ "$b" -ge -100 ] && [ "$b" -le 100 ]); then
# whether to use above one or this one is correct
if [ "$a" -ge -100 ] && [ "$a" -le  100 ] || [ "$b" -ge -100 ] && [ "$b" -le 100 ]; then
	echo $((a + b))
	echo $((a - b))
	echo $((a * b))
	echo $((a / b))
fi
