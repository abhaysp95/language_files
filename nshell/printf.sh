#!/usr/bin/env sh

for i in $( seq 1 10 ); do  # use -s ' ' for seperater and -w for equal width
	printf "%04d\t" "$i"
done
echo

for i in $( seq 1 10 ); do
	printf "%x\t" "$i"
done
echo

for i in $( seq 1 10 ); do
	printf "%X\t" "$i"
done
echo

for i in $( seq 10 15 ); do
	printf "%04d\t is %X\t in Hex.\n" "$i" "$i"
done
echo

for i in $( seq 5 10 ); do
	printf "%.10s is %X in HEX.\n" "$i............." "$i"
done
echo

printf -v myvar "%3d\n" "0xF9"
echo "Saved value is $myvar"
