#!/usr/bin/env bash

name=( ab bcd defg )

echo "${name[@]}"
echo "${name[*]}"  # all of the items of array
echo "${!name[*]}"  # all the indexes in the array
echo "${#name}"  # shows the first count
echo "${#name[*]}"  # length of the array
echo "${#name[2]}"  # length of index 0

# difference between name[@] and name[*] is that when in quotes
# like "${name[*]}" it expands into a single string whereas
# "${name[@]}" in double-quotes it behaves like ${name[*]}
# meaning in seperate words


echo "------------------"

for i in "${name[@]}"; do
	echo "$i"
done
