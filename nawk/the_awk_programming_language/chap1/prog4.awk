# normal string should be put in double quotes(""),
# as when run in command line you'll already be using
# single quotes and there's also ,(comma) too to remember
# about

{ print "total pay for", $1, "is", $2 * $3 }

# for more better printing use printf

# with printf no blanks or newlines are created themselves
{ printf("total pay for %s is $%.2f\n", $1, $2 * $3) }
# %-8s means left justified in a field 8 character wide
# use %+8s to make it right justified
{ printf("%-8s $%6.2f\n\n", $1, $2 * $3) }
