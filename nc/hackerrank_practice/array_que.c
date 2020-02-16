/** Name -> Abhay Shanker Pathak
Date -> 2020-02-15
Description -> Add two long integers
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-15 */

#include<stdio.h>
#include<string.h>
#define size 100

void Sum(char s1[], char s2[], int ,int );

int main(int argc, char *argv[]){
	char s1[size], s2[size];
	long a, b;
	/* int i, j, k, s3[size], sum = 0, r = 0, c = 0; */
	printf("Enter first numbers: ");
	fgets(s1, sizeof(s1), stdin);
	printf("Enter second number: ");
	fgets(s2, sizeof(s2), stdin);
	a = strlen(s1);
	b = strlen(s2);
	printf("\nSize of first number set: %ld", a-1);
	printf("\nSize of second number set: %ld", b-1);
	printf("\n");

	if ( a >= b)
		Sum(s1, s2, a-1, b-1);
	else
		Sum(s2, s1, b-1, a-1);

	/* printf("%c", s1[a-2]); */
	/* printf("\n%d", s1[a-2] - 48); */

	/* if (a >= b) { */
		/* for (i = a - 2, j = b - 2, k = 0; j >=0 ; i--, j--, k++) { */
		/* 	sum = s1[i] + s2[j]; */
		/* 	if (sum > 9) { */
		/* 		r = sum % 10; */
		/* 		s3[k] = (r + c) - 48; */
		/* 		/1* printf("%d", r + c); *1/ */
		/* 		c = sum / 10; */
		/* 	} */
		/* 	else */
		/* 		/1* printf("%d", sum + c); *1/ */
		/* 		s3[k] = (sum + c) - 48; */
		/* 		if (sum + c < 9) */
		/* 			c = 0; */
		/* } */
		/* for (j = i; j >= 0; j--, k++) { */
		/* 	s3[k] = s1[j] - 48; */
		/* 	/1* printf("%d", s1[j] - 48); *1/ */
		/* } */
	/* } */
	/* // print sum */
	/* printf("\nSum is: \n"); */
	/* for (j = k - 1; j >= 0; j--) { */
		/* printf("%d",s3[j]); */

		/* for (i = a - 2, j = b - 2; k = a - 2; j >= 0; i--, j--, k--) { */

/* 		} */
/* 	} */
	return 0;
}

void Sum(char s1[], char s2[], int a, int b) {
	/* int dsum = 0; */
	/* for (int i = 0; i < a; i++) { */
	/* 	printf("%c", s1[i]); */
	/* 	dsum = dsum + (s1[i] - 48); */
	/* } */
	/* printf("\n%d",dsum); */
	/* printf("\n"); */
	/* for (int j = 0; j < b; j++) { */
	/* 	printf("%c", s2[j]); */
	/* } */
	int s3[size];
	int i = a - 1, j = b - 1, k = a - 1;
	int carry = 0, sum = 0;
	while (j >= 0) {
		sum = (s1[i] + s2[j] + carry) - 48;
		s3[k] = sum % 10;
		carry = sum / 10;
		i--;
		j--;
		k--;
	}
	while (i >= 0) {
		sum = s1[i] + carry - 48;
		s3[k] = sum % 10;
		i--;
		k--;
	}
	for (i = 0; i <= a - 1; i++) {
		printf("%d", s3[i]);
	}
}
