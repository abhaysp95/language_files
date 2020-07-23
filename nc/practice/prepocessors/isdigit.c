// check if isdigit

#include <stdio.h>
#define ISDIGIT(y) (y >= 48 && y <= 57)

// main function
int main(int argc, char* argv[]) {
	char ch;
	char ch1;
	printf("Enter the digit: ");
	scanf("%c", &ch);  // 5
	scanf("%d", &ch1);  // 7  format specifies type char * but argument has type int *
	printf("You entered: %c\n", ch);  // 5
	printf("You entered: %d\n", ch);  // 53
	printf("You entered: %c\n", ch1);  //
	printf("You entered: %d\n", ch1);  // 7
	if (ISDIGIT(ch)) {
		printf("It's a digit\n");
	}
	else {
		printf("It's not a digit\n");
	}
	return 0;
}
