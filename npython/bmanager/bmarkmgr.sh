#!/usr/bin/env bash

mainpy=""

if [ "$1" == '-p' ] || [ "$1" == '--path' ]; then
	mainpy="$2"
	shift
	shift
else
	mainpy="main.py"
fi

python3 "${mainpy}" $@
