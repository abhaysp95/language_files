#!/bin/bash

files=$(ls)


count=0
for file in ${files}; do  " don't close inside double quotes if you want expansion"
	echo "${file}"
	count=$(( count + 1 ))
	echo "$count"
done
