#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-02-21
# Description: Script to remove empty files or directories(maybe)
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-02-21

printf "Input the file or directory name\n(path after home directory)\n"
read -r file_name
name="$HOME"/"$file_name"

if [ -e "$name" ]; then
	echo Object "$name" exists
	if [ -s "$name" ]; then
		#echo "$name" has data in it.
		printf "%s" "$name" "has data in it\nDeletion not performed."
	else
		printf "%s" "$name" " doesn't have data in it\nDeleting it"
		rm "$name"
	fi
else
	echo Object "$name" doesn\'t exists
fi
