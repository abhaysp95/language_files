# in awk, user-created variables are not declared

$3 > 15 { emp = emp + 1 }
END { print emp, "employee worked more than 15 hours" }

# awk variables used as numbers begin life with value 0, so we
# didn't need to initialize emp
