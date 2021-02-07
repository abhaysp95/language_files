{ last = $0 }
END { print last }

# although NR retains its value in an END action, $0 doesn't
