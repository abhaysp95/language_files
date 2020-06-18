/**

Abhay Shanker Pathak
abhaysp9955@gmail.com
https://github.com/coolabhays


recursive function for following math function
f(n) = 1, if n = 1
f(n) = 2 * f(n -1), if n >= 2 */


#include<stdio.h>

// function for recursion
int recursive_func(int number) {
	if (number == 1) {
		return 1;
	}
	else {
		return 2 * recursive_func(number - 1);
	}
}

// main function
int main(int argc, char* argv[]) {
	int num = 0;
	printf("Enter the number: ");
	scanf("%d", &num);
	int result = recursive_func(num);
	printf("Result is: %d", result);
	return 0;
}
