#!/usr/bin/env sh

if [[ $# -le 0 ]]; then
	echo "You didn't pass any files as argument to the script."
	echo "Usage: " "$0" "my-file1  my-file2"
	exit
fi

for arg in "$@"
do
	# Does it actually exist?
	if [[ ! -e "$arg" ]]  # check if file exist and if a file
	then
		echo "* skipping ${arg}"
		continue
	#else
		#echo "-e option will if file dosn't exist, so this is showing because file exist"
	fi

	# Is it a regular file
	if [ -f "$arg" ]
	then
		echo "* ${arg} is regular file!"
	else
		echo "* ${arg} isn't a regular file!"
	fi

	[ -b "$arg" ] && echo "* ${arg} is a block device"
	[ -d "$arg" ] && echo "* ${arg} is a directory"
	[ ! -d "$arg" ] && echo "* ${arg} is a not a directory"

	[ -x "$arg" ] && echo "* ${arg} is a executable"
	[ ! -x "$arg" ] && echo "* ${arg} is a not executable"

	[ -h "$arg" ] && echo "* ${arg} is a symbolic link"
	[ ! -h "$arg" ] && echo "* ${arg} is a not symbolic link"

	[ -s "$arg" ] && echo "* ${arg} is a nonzero size"
	[ ! -s "$arg" ] && echo "* ${arg} is a zero size"

	# [[ && ]] or [  ] && [  ] for multiple test cases
	[[ -r "$arg" && -d "$arg" ]] && echo "* ${arg} is a readable directory"
	[[ -r "$arg" && -f "$arg" ]] && echo "* ${arg} is a readable directory and regular file"
done
