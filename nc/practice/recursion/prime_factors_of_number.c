// program to get prime factors of number recursively and non-recursively

#include<stdio.h>
#define SIZE 30

// without recursion
void primeFactorsWithoutRecursion(int num) {
	int i, j;
	int flag;
	for (i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			// printf("\nDiveded by %d\n", i);
			flag = 0;
			for (j = 2; j <= i/2; j++) {
				if (i % j == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				printf("Prime factor is %d\n", i);
			}
		}
	}
}

// check if prime with recursion
int if_prime(int num, int count) {
	if (count == 1) {
		return 1;
	}
	else {
		if (num % count == 0) {
			return 0;
		}
		else {
			if_prime(num, count - 1);
		}
	}
	// no return as after first return from above if prime
	// it'll will return 0, which we not want
}

// with recursion
int primeFactorsWithRecursion(int num, int count) {
	int is_prime = 0;
	if (count == 1) {
		return 0;
	}
	if (num % count == 0) {
		// printf("Factorial is %d\n", count);
		is_prime = if_prime(count, count / 2);
		// printf("I'm here\n");
		if (is_prime == 1) {
			printf("Factorial %d is prime\n", count);
		}
	}
	primeFactorsWithRecursion(num, count - 1);
	return 0;
}

// main
int main(int argc, char* argv[]) {
	int number = 0;
	printf("Enter the number: ");
	scanf("%d", &number);
	primeFactorsWithRecursion(number, number / 2);
	return 0;
}
