afunc() {
	echo "arg0: $0"  # $0 always stays the same
	echo "arg1: $1"
	echo "arg1: $2"
}

case "$1" in
	"-a") afunc $1 $2 ;;
	-b) shift; afunc $1 ;;
	*) echo "this" ;;
esac
