// get the running sum of 25 natural numbers using recursion

#include<stdio.h>

// recursive function
int addnumbers(int num) {
	if (num == 0) {
		return 0;
	}
	return num + addnumbers(num - 1);
}

// main
int main(int argc, char* argv[]) {
	unsigned int num = 0, sum = 0;
	printf("Enter the number: ");
	scanf("%u", &num);
	sum = addnumbers(num);
	printf("Sum is: %u\n", sum);
	return 0;
}
