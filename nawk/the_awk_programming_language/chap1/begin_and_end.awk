# the special pattern BEGIN matches before the first line of
# the first input file is read and END matches after the last
# line of the last file has been processed

# BEGIN to print heading

BEGIN { print "NAME RATE HOURS"; print "" }
{ print }

# the second print will print nothing in next line
# third print will print all the data from the file
