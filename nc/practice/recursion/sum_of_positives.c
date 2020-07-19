// sum of 5-digit positive integer with and without recursion

#include<stdio.h>

// without recursion
int sum_without_recursion(int num) {
	int sum = 0, remain = 0;
	while (num > 0) {
		remain = num % 10;
		num = num / 10;
		sum = sum + remain;
	}
	return sum;
}

// with recursion
int sum_with_recursion(int num) {
	int sum, remain;
	if (num <= 0) {
		return 0;
	}
	remain = num % 10;
	sum = remain + sum_with_recursion(num / 10);
	return sum;
}

// main
int main(int argc, char *argv[]) {
	int number = 0, sum = 0;
	printf("Enter the number of 5-digits: ");
	scanf("%d", &number);
	sum = sum_with_recursion(number);
	printf("Sum is %d", sum);
	return 0;
}
