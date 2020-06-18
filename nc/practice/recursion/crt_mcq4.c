// find the result of following function

#include<stdio.h>
#include<stdlib.h>

void super_write_vertical(int);

void super_write_vertical(int number) {
	if (number < 0) {
		printf("-");
		super_write_vertical(abs(number));
	}
	else if (number < 10) {
		printf("%d\n", number);
	}
	else {
		super_write_vertical(number / 10);
		printf("%d\n", number % 10);
	}
}

int main(int argc, char *argv[]) {
	int num = 0;
	printf("Enter the number: ");
	scanf("%d", &num);
	super_write_vertical(num);
}
