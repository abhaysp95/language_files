/** Name -> Abhay Shanker Pathak
Date -> 2020-03-10
Description -> Using calloc and free in program, calculating the sum of n
numbers entered by user
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-10 */

#include<stdio.h>
#include<stdlib.h>

int sum(int );

int main(int argc, char *argv[]){
	int n, res;
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	res = sum(n);
	printf("\nSum is = %d", res);
	return 0;
}

int sum(int n) {
	int tot = 0;
	int *ptr = (int *)calloc(n, sizeof(int));
	if (ptr == NULL) {
		printf("Error! memory not allocated. ");
		exit(0);
	}

	printf("\nEnter the elements: ");
	for (int i = 0; i < n; i++) {
		printf("\n%d: ", i + 1);
		scanf("%d", ptr + i);
		tot += *(ptr + i);
	}
	free(ptr);
	return tot;
}
