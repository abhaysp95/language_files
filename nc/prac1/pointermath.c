/** Name -> Abhay Shanker Pathak
Date -> 2020-02-09
Description -> basic addition and absolute difference with pointer
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-09 */

#include<stdio.h>
#include<stdlib.h>

void update(int *, int *);

int main(int argc, char *argv[]) {
	int a, b;
	int *pa = &a, *pb = &b;
	printf("\nEnter the numbers: ");
	scanf("%d %d", &a, &b);
	update(pa, pb);
	printf("%d\n%d", a, b);
	return 0;
}

void update(int *a, int *b) {
	/* int *c; */
	/* c = a; */
	/* *a = *c + *b; */
	/* *b = (*c - *b); */

	// In the above method *a as well as *c are pointing to same block,
	// hence, once *a = 9, *c also is equal to 9

	int c;
	c = *a;
	*a = c + *b;
	*b = abs(c - *b);
}

