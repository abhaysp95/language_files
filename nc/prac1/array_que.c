/** Name -> Abhay Shanker Pathak
Date -> 2020-02-15
Description -> Add long long long int
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-15 */

#include<stdio.h>
#include<string.h>

#define size 100

void Sum(char s1[], char s2[], int , int );

int main(int argc, char *argv[]){
	char s1[size], s2[size];
	long a, b;
	//int i, j, sum = 0, c = 0, r = 0;
	printf("\nEnter first number: ");
	fgets(s1, sizeof(s1), stdin);
	printf("\nEnter second number: ");
	fgets(s2, sizeof(s2), stdin);
	a = strlen(s1);
	b = strlen(s2);
	/* printf("\nNumber of digits in first number: %ld", a); */
	/* printf("\nNumber of digits in second number: %ld", b); */

	if (a >= b)
		Sum(s1, s2, a - 1, b - 1);
	else
		Sum(s2, s1, b - 1, a - 1);

	return 0;
}

void Sum(char s1[], char s2[], int a, int b) {
	int s3[size];
	int i = a - 1, j = b - 1, k = a - 1;
	int carry = 0, sum = 0;
	while (j >= 0) {
		sum = ((s1[i] - 48) + (s2[j] - 48) + carry);
		s3[k] = sum % 10;
		carry = sum / 10;
		i--; j--; k--;
	}
	while (i >= 0) {
		sum = ((s1[i] - 48) + carry);
		s3[k] = sum % 10;
		i--; k--;
	}
	printf("Sum is: ");
	for (i = 0; i < a; i++) {
		printf("%d", s3[i]);
	}
}
