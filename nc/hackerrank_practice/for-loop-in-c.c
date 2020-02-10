/** Name -> Abhay Shanker Pathak
Date -> 2020-02-10
Description -> solving a hackerrank problem for loop
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-10 */

#include<stdio.h>


int main(int argc, char *argv[]){
	int a, b, i;
	printf("\nEnter the first and second number of range: ");
	scanf("%d %d", &a, &b);
	for (i = a; i <= b; ++i) {
		/* printf("%d\n",i); */
		if (i >= 1 && i <= 9) {
			if (i == 1) {
				printf("one\n");
			}
			else if (i == 2) {
				printf("two\n");
			}
			else if (i == 3) {
				printf("three\n");
			}
			else if (i == 4) {
				printf("four\n");
			}
			else if (i == 5) {
				printf("five\n");
			}
			else if (i == 6) {
				printf("six\n");
			}
			else if (i == 7) {
				printf("seven\n");
			}
			else if (i == 8) {
				printf("eight\n");
			}
			else if (i == 9) {
				printf("nine\n");
			}
		}
		else {
			if (i % 2 == 0) {
				printf("even\n");
			}
			else
				printf("odd\n");
		}
	}
	return 0;
}
