if ps axh | grep "tomcat" | grep -v grep 1> /dev/null; then
	echo "yes"
else
	echo "no"
fi
