#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-02-25
# Description: Working with compound testing in if
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-02-25

tstfile=$HOME/temp/testfile

# use || for 'or' condition
if [ -d "$HOME" ] && [ -w "$tstfile" ]; then
	printf "%s exists and you can write on the %s file" "$HOME" "$tstfile"
else
	printf "You can't write on %s file" "$tstfile"
fi
