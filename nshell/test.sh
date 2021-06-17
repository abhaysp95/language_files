#!/usr/bin/env bash


declare -a commands=(
#"fd --version",
"convert --version",
"dmenu -v"
)

for cmd in "${commands[@]}"; do
	echo "cmd: ${cmd}"
	"${cmd}" 2&>1 >/dev/null
done
