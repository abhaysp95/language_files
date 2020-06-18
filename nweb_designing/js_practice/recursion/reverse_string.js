let reverse_string = given_str => {
	return given_str.length === 0
		? ''
		: given_str[given_str.length - 1]
		+ reverse_string (given_str.substr(0, given_str.length - 1));
}
// substr method extracts string according to given positions

reverse_string ('given name');
