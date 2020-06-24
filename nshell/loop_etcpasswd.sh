#!/usr/bin/env sh

# changing the IFS value

IFS.OLD=$IFS
IFS=$'\n'
for entry in $(cat /etc/passwd); do
	echo "$entry - "
	IFS=:
	for value in $entry; do  # don't double quote or else it'll not split
		printf "\t%s\n" "${value}"
	done
	echo
done
