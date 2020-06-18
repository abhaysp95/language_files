let factorial = number => {
	debugger;
	return number <= 1
		? 1
		: number * factorial (number - 1);
}
