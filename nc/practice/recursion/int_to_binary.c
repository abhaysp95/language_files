// convert the given positive integer to binary

#include<stdio.h>
#include<math.h>
#define SIZE 30

// conversion without recursion
void inttobinwithoutrecursion(int num) {
	int count = 0, bin_is[SIZE];
	int i = 0;
	while (num > 0) {
		bin_is[count] = num % 2;
		num = num / 2;
		count-=-1;
	}
	for (i = count - 1; i >= 0; i--) {
		printf("%d", bin_is[i]);
	}
}

//conversion with recursion
int inttobinwithrecursion(int num) {
	if (num == 0) {
		return 0;
	}
	inttobinwithrecursion(num / 2);
	printf("%d", num % 2);
}

// main
int main(int argc, char* argv[]) {
	int number = 0;
	printf("Enter the number: ");
	scanf("%d", &number);
	// inttobinwithoutrecursion(number);
	inttobinwithrecursion(number);
	printf("\n");
	return 0;
}
