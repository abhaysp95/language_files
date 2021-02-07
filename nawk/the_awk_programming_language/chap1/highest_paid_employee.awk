# get highest paid(hourly) employee

$2 > maxpay { maxpay = $2; maxemp = $1 }
END { print "highest hourly rate:", maxpay, "for:", maxemp }

# no need to add extra spaces, this is print, not printf
