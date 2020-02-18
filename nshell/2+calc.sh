#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-02-18
# Description: basic calc with inline input redirection
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-02-18

var1=10.46
var2=43.67
var3=33.2
var4=71

var5=$(bc << EOF
scale = 4
a1 = ($var1 * $var2)
b1 = ($var3 * $var4)
a1 + b1
EOF
)

echo Final answer: "$var5"
