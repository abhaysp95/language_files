#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-02-21
# Description: Using file comparisions with test comparision
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-02-21

if [ -d "$HOME" ]; then		# file exists and is directory
	echo "$HOME exists."
else
	echo "$HOME doesn't exists"
fi

if [ -e "$HOME"/dox ]; then	# file exists
	echo "dox exists."
else
	echo "dox doesn't exists"
fi

if [ -f "$HOME"/dox/nshell/calc.sh ]; then
	echo "File exists."
else
	echo File doesn\'t exists
fi

gpath="$HOME"/dox/nshell

if [ "$gpath"/2+calc.sh -nt "$gpath"/3+calc.sh ]; then
	echo "First one is newer than the other."
else
	echo "Second one is newer than other."
fi

if [ "$gpath"/calc.sh -ot "$gpath"/test.sh ]; then
	echo "First one is older than other."
else
	echo "Second one is older than other."
fi
