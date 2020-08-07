#!/usr/bin/env bash

#for file in $(cat create_files.txt); do
	#echo "$file"
#done

file_name=$1

while IFS= read -r file; do
	echo "$file"
	touch "$file"
done < <( cat $1 )
