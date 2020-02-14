/** Name -> Abhay Shanker Pathak
Date -> 2020-02-14
Description -> Fibonacci Series
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-14 */

#include<stdio.h>

int main(int argc, char *argv[]){
	int a = 1, b = 1, c, n, i;
	printf("\nEnter the number: ");
	scanf("%d", &n);
	printf("%d %d ", a, b);
	for (i = 0; i < n; i++) {
		c = a + b;
		printf("%d ", c);
		a = b;
		b = c;
	}
	return 0;
}
