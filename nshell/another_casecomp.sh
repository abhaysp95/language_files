#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-03-11
# Description: just using case
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-03-11

file_in=ls | rg new
case "$file_in" in
	*.c)
		printf 'This is a C file';;
	*.sh)
		printf 'This is a shell file';;
	*.java)
		printf 'This is a java file';;
	*.md)
		printf 'This is a markdown file';;
	*)
		printf 'Unknown file';;
esac
