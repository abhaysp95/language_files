#!/usr/bin/env sh

if [ "$1" = "-h" ]; then
	echo "Usage: ./change_extension.sh [arg] old_ext new_ext"
	printf "\t-d:\t\tdry run the script\n"
	printf "\t\tGive the old_extension and then new extension as argument\n"
	printf "\t-h:\t\tget help\n"
	exit 0
fi

dry_run() {
	for file in *."$2"; do
		new_name="$(basename "${file}" ".$2")"
		echo "${file} renamed to ${new_name}.$3"
	done
}

change_ext() {
	for file in *."$1"; do
		new_name="$(basename "${file}" ".$1")"
		mv -v "${file}" "${new_name}.$2"
	done
}

if [ "$1" != '-d' ]; then
	# "$@" in here makes $1(i.e., arguments) of script, the $1 for function also
	change_ext "$@"
else
	dry_run "$@"
fi
