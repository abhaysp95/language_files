#!/usr/bin/env bash


function first_function() {
	handshake=("wink" "double" "blink" "close your eyes" "jump")  # array
	echo "1"
	code=$1
	result=()
	if ((code >> 4)); then
		echo "2"
		for i in {3..0..-1}; do
			echo "3"
			((1 & (code >> i))) && \
				result+=("${handshake[$i]}")
			echo "4"
		done
	else
		for i in {0..3}; do
			echo "5"
			((1 & (code >> i))) && \
				result+=("${handshake[$i]}")
			echo "6"
		done
	fi
	echo "${result[$@]}"
}

# first_function "$@"  # execute first_function with given parameters

function second_function() {
	handshake=("wink" "double" "blink" "close your eyes" "jump")  # array
	code=$1
	result=()
	(( code >> 4 )) && range="3 -1 0" || range="0 3"
	for i in $(eval "seq ${range}"); do
		(( 1 & ( code >> 1 ) )) && result+=( "${handshake[$i]}" )
	done
	join , "${result[@]}"
}

# second_function "$@"

function third_function() {
	handshake=("wink" "double" "blink" "close your eyes" "jump")  # array
	code=$1
	tcode=$1
	while [ "$tcode" -gt 0 ]; do
		echo "$tcode"
		tcode=$(( tcode >> 1 ))
	done
	tcode=$1
	echo "$(( "$tcode" >> 3 ))"
	echo "another thing"
	(( code >> 4 )) && range="3 -1 0" || range="0 3"
	for i in $(eval "seq ${range}"); do
		echo "$i"
		echo "${handshake[$i]}" && (( 1 & ( code >> 1 ) ))
	done
}

# third_function "$@"

function fourth_function() {
	code=$1
	(( code >> 4 )) && echo "this" || echo "that"
}

function fifth_function() {
	code=$1
	if (( code >> 4 )); then
		echo "this"
	else
		echo "that"
	fi
}

function driver_of_fifth() {
	for i in {0..30}; do
		echo "$i"
		fourth_function "$i"
	done
}

# echo "10" && echo "done"

function seventh_function() {
	for i in $(eval seq "3 -1 0"); do
		echo "$i"
	done
}
# seventh_function

function eigth_function() {
	readonly handshake=("wink" "double" "blink" "close your eyes" "jump")
	readonly code=$1
	(( code >> 4 )) && range=({3..0..-1}) || range=({0..3})
	for i in "${range[@]}"; do
		# remember to perform bitwise and & right shift correctly
		if (( 1 & ( code >> i ) )); then
			[[ -n "$result" ]] && result+=","
			result+="${handshake[$i]}"
		fi
	done

	echo "$result"
}

eigth_function "$1"
