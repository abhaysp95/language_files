/**

Abhay Shanker Pathak
abhaysp9955@gmail.com
https://github.com/coolabhays


recursive function to print numbers from n to 0 */


#include<stdio.h>

// function to print
void recursive_print(int number) {
	if (number == 0) {
		printf("0");;
	}
	else {
		printf("%d", number);
		recursive_print(number - 1);
	}
}

// main function
int main(int argc, char* argv[]) {
	long long int num = 0;
	printf("Enter the number: ");
	scanf("%lld", &num);
	recursive_print(num);
	return 0;
}
