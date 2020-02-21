#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-02-21
# Description: Looking at string size
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-02-21
#
val1=testing
val2=''
#
if [ -n "$val2" ]; then		# here "$val1" quoting isn't necessary
	# -n checks if string has length greater than zero
	echo "This string '$val1' is not empty"
else
	echo "This string '$val2' is empty"
fi
#
if [ -z "$val1" ]; then
	# -z checks if string has length of zero
	echo "The string $val2 is empty"
	# local variables are already quoted by echo so no need
else
	echo "The string $val2 isn't empty"
fi
#
if [ -z $val3 ]; then
	echo "The string $val3 is empty"
else
	echo "The string $val3 isn't empty"
fi
