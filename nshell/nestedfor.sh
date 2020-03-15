#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-03-14
# Description: Doing nested for loop
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-03-14

# for within for <<<
for (( i = 1; i <= 5; i++ ))
do
	printf 'Starting loop %s:\n' "$i"
	for (( j = 1; j <= 10; j++ ))
	do
		printf '\tStarting loop %s:\n' "$j"
	done
done
# >>>


# for within while <<<
i=1
h=5
until [ $h -eq 0 ]
do
	while [ $i -le 4 ]
	do
		printf 'Starting Outer loop %s:\n' "$i"
		for (( j = 1; j <= 2; j++ ))
		do
			k=$(( i * j))
			printf '\tStarting Inner loop %s:\n' "$j"
			printf '\tInner loop: %s * %s = %s\n' "$i" "$j" "$k"
		done
		echo 'Outer loop: ' "$(echo "scale=4; $h / $i" | bc)"
		i=$(( i + 1))
	done
	h=$(( h - 1))
done
# >>>
