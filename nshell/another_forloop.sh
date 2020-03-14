#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-03-12
# Description: Another loop practice script
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-03-12

for file in "$HOME"/* "$HOME"/dox/*
do
	if [ -d "$file" ]; then
		echo "$file is directory"
	elif [ -f "$file" ]; then
		echo "$file is a file"
	fi
done
