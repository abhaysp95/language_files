#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-02-25
# Description: learning case comparision in shell
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-02-25

case $USER in
	raytracer | abhay)
		echo "Welcome, $USER"
		echo "Please enjoy your visit";;
	testing)
		echo "Special testing account";;
	thor)
		echo "Welcome, God Of Thunder";;
	*)
		echo "Sorry, but you are not welcome here";;
esac
