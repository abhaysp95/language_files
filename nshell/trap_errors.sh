#!/usr/bin/env bash


# for more info: https://medium.com/@dirk.avery/the-bash-trap-trap-ce6083f36700



# trap catches, ERR, EXIT, SIGINT, SIGTERM and KILL

#trap 'catch' ERR

#trap 'catch $? $LINENO' ERR

set -e  # exit-on-error mode

trap 'catch $? $LINENO' EXIT

catch() {
	echo "catching"
	if [ "$1" != "0" ]; then
		# error handling goes here
		echo "Error $1 occurred in $2"
	fi
	#exit 1
}

#simple() {
	#echo "I'm from simple"
	#dmen -v >/dev/null 2>&1
	# if this line is not last, function will return success as status and catch
	# will not be called(think of each function as subshell)
#}

#simple

another_simple() {
	dmen -v >/dev/null 2>&1
	echo "This is from another_simple"
}

another_simple
echo "after another_simple call"

#echo "before error"
#dmen -v >/dev/null 2>&1
#echo "after error"

