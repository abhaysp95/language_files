# if there's no error, there will be no output

NF != 3 { print $0, "number of fields is not equal to 3" }
$2 < 3.35 { print SO, "rate is below minimum wage" }
$2 > 10 { print $0, "rate exceeds $10 per hour" }
$3 < 0 { print $0, "negative hours worked" }
$3 > 60 { print $0, "too many hours worked" }
