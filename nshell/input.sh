#!/usr/bin/env sh

file=$1

if [[ "$file" == "" || (! -f "$file") ]]; then
	echo "Using Standard Input"
	file="/dev/stdin"
fi

while read -r line
do
	echo "$line"
done < "${file}"
