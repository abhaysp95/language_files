#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-03-14
# Description: Basic use of while loop
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-03-14

# while loop <<<
i=10
while [ $i -gt 0 ]; do
	echo "hey $i"
	i=$(( i - 1 ))
done
# >>>

# until loop <<<
j=50
until [ $j -eq 0 ]
do
	echo "Number is $j"
	j=$(( j - 1 ))
done
# >>>

# until multiple test commands <<<
k=10
until echo $k
	[ $k -eq 0 ]
do
	echo Inside the loop: $k
	k=$(( k - 2 ))
done
# >>>
