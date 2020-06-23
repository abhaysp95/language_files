#!/usr/bin/env sh

echo "Enter the number corresponding to the favorite color:"

select COLOR in blue yellow green red
do
	echo "Your selection is: ${COLOR}"
	break
done
