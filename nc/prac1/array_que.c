/** Name -> Abhay Shanker Pathak
Date -> 2020-02-15
Description -> Add long long long int
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-15 */

#include<stdio.h>
#include<string.h>

#define size 100

int main(int argc, char *argv[]){
	char s1[size], s2[size];
	long a, b;
	int i, j, sum = 0, c = 0, r = 0;
	printf("\nEnter first number: ");
	fgets(s1, sizeof(s1), stdin);
	printf("\nEnter second number: ");
	fgets(s2, sizeof(s2), stdin);
	a = strlen(s1);
	b = strlen(s2);
	printf("\nNumber of digits in first number: %ld", a);
	printf("\nNumber of digits in second number: %ld", b);

	printf("\n");
	for (i = 0; i < a; i++) {
		printf("%c", s1[i]);
	}
	/* printf("%c", s1[a-2]); */
	/* printf("\n%d", s1[a-2] - 48); */

	if (a >= b) {
		for (i = a-2, j = b - 2; j >= 0; j--, i--) {
			/* subtracting increased value to get int from ascii */
			sum = (s1[i] - 48) + (s2[j] - 48);
			/* printf("\nSum is %d", sum); */
			if (sum > 9) {
				r = sum % 10;
				printf("%d", r + c);
				c = sum / 10;
			}
			else
				printf("%d", sum + c);
		}
		for (j = i - 1; j >= 0; j--) {
			printf("%c",s1[j]);
		}
	}
	return 0;
}
