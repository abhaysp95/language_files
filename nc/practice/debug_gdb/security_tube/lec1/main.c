#include <stdio.h>
#include <stdlib.h>

int thisIsGlobal;

int addNumber(int number_1, int number_2) {
	static int thisIsStatic;
	int sum = 0;
	sum = number_1 + number_2;
	return sum;
}

int subtractNumber(int number_1, int number_2) {
	int difference = 0;
	difference = number_1 - number_2;
	return difference;
}

int main(int argc, char **argv) {
	int input_1 = atoi(*(argv + 1));
	int input_2 = atoi(*(argv + 2));
	printf("Welcome to sum/difference program...\n");
	printf("Sum of %d and %d is %d\n", input_1, input_2, addNumber(input_1, input_2));
	printf("Difference of %d and %d is %d\n", input_1, input_2, subtractNumber(input_1, input_2));
	return 0;
}
