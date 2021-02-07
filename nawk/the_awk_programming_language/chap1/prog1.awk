# very first program from book

# awk has pattern-action philoshphy, both pattern and action
# are optional

# you don't need to write awk in the file(provide arg file)

# you can run this file with $(awk -f prog_file args...)

# pattern   action
$3 > 0 { print $1, $2 * $3 }
