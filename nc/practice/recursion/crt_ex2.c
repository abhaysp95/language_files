/**

Abhay Shanker Pathak
abhaysp9955@gmail.com
https://github.com/coolabhays


write a recursive function for 2^n-1 integers */


#include<stdio.h>

// function for recursion
void num_recursed(int number) {
	if (number == 1) {
		printf("1");;
	}
	else {
		num_recursed(number - 1);
		printf("%d", number);
		num_recursed(number - 1);
	}
}

// main function
int main(int argc, char* argv[]) {
	int num = 0;
	printf("Enter the number: ");
	scanf("%d", &num);
	num_recursed(num);
	printf("\n");
	return 0;
}
