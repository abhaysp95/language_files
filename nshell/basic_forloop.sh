#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-03-11
# Description: basic for loop use
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-03-11

# IFS(internal field seperator) by default recognizes 'a spaece', 'a tab' and 'a newline' as seperator.
# To change this behaviour you can mention only one of it, then it only recognize only mentioned one as seperator
# You can just mention like IFS=$'\n' but if you want the default in script later, you can do

IFS_old=$IFS
IFS=$'\n'
for current_dir in $(ls -d */); do
	current_dir=$(echo "$current_dir" | sed 's?/? ?g')
	echo "Next directory is $current_dir"
done
IFS=$IFS_old

# let's change the IFS value one more time
echo
IFS=:
for member in $(cat /etc/passwd); do
	printf "\nNext member is %s\n" "$member"
	echo "That same member $member"
done
exit 0
