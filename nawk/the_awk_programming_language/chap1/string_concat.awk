{ names = names $1}
NR != 6 { names = names ", " }
END { print names }

# above is my way


# { names = names $1 " " }
# collect all the employees names into a single string, by appending each name and a blank to the previous value in the variable names
