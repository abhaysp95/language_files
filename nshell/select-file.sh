#!/usr/bin/env sh

# improvement required

echo "Select file by number: "

files=( "$(find . -type f | sed 's/\.\///' | tr '\n' ' ')" )

select file in "${files}"; do
	echo "${file}"
	break
done
