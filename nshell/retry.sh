#!/usr/bin/env sh

n=0
command=$1

while ! "${command}" && [ "${n}" -le 5 ]; do
	sleep "${n}"
	(( n+=1 ))
	echo "Retrying... #${n}"
done