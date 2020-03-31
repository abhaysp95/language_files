#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date:	2020-03-29
# Description: Finding average
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-03-29

# Find average of the entered numbers <<<
echo 'Enter the count: '
read -r count
lcount="$count"
sum=0

while [ "$count" -gt 0 ]; do
	read -r num
	# printf "Sum is: %s \nNum is: %s\n" "$sum" "$num"
	sum=$(( sum + num ))
	# printf "Sum after is: %s\n" "$sum"
	count=$(( count - 1 ))
done

# avg correct upto three decimal points
# printf "Avg is: %.3f" "$(( sum / lcount ))"
printf "Avg is: %.3f" "$(echo "scale=5; $sum / $lcount" | bc)"
# >>>
