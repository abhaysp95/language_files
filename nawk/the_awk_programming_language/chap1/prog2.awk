# NF = number of fields

# awk counts the number of fields in the current input line
# and stores the count in a built-in variable called NF.

# $NF means ${number of field}, it would be a number, like
# say $NF and NF is 3 so $NF == $3

# this would be useful if you just want to print the last
# field of every input line and each line have different
# number of fields

# use this file with ds2.data as example to check out

{ print NF, $1, $NF }
