// example for my_func

# ifndef __myfile_h
	#define __myfile_h

int give_fibonacci(int number) {
	if (number <= 2) {
		return 1;
	}
	return give_fibonacci(number - 1) + give_fibonacci(number - 2);
}

# endif

int give_factorial(int number) {
	if (number <= 1) {
		return 1;
	}
	return number * give_factorial(number - 1);
}
