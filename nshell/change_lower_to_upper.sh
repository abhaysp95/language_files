#!/usr/bin/env sh

for i in "$(cat $1)"; do
	B="$(echo -n "${i:0:1}")" \
		| tr "[:lower:]" "[:upper:]"
	echo -n "${B}${i:1}"
done

echo -e "\n"
