// reverse string recursively without using array/string

#include<stdio.h>

void print_reverse(char *, int);

void print_reverse(char *str, int length) {
	if (length == 0) {
		return;
	}
	else {
		printf("%c", str[length - 1]);
		print_reverse(str, length - 1);
	}
}

int main(int argc, char *argv[]) {
	char string[20];
	int len = 0, i = 0;
	printf("Enter the String: ");
	scanf("%s", string);
	// printf("%s", string);
	while (string[i] != '\0') {
		len = len + 1;
		i++;
	}
	print_reverse(string, len);
	return 0;
}
