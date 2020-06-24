#!/bin/bash

# for bashv > 4.x
# sed not working correctly
first_method() {
	mapfile -t -d ' ' files < <( find . -type f | tr '\n' ' ' | sed 's/\.\///' )
	echo "${files[@]}"
	echo "${#files[@]}"
	declare -p files
}

first_method
echo "First method completed"
echo

# currently not working
second_method() {
	files=()
	while IFS= read -r line; do  # IFS= , turns of stripping of leading and trailing whitespaces
		my_array+=( "$line" )
	done < <( find . -type f | sed 's/\.\///' )
	echo "${my_array[@]}"
	echo "${#files[@]}"
}

second_method
echo "Second method completed"
echo

# working perfectly
third_method() {
	IFS=$'\n' read -r -d '' -a new_array < <( find . -type f | sed 's/\.\///' && printf '\0' )
	echo "${new_array[@]}"
	echo "${#new_array[@]}"
}

third_method
echo "Third method completed"
echo
