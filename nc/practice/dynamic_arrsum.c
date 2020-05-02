/** Name -> Abhay Shanker Pathak
Date -> 2020-02-23
Description -> Create a array dynamically and print it's sum
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-23 */

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	int *arr;
	int n;
	printf("\nEnter the count: ");
	scanf("%d", &n);
	arr = (int *)malloc(n*(sizeof(int)));
	if (arr == NULL) {
		printf("\nMemory not allocated");
		exit (0);
	}
	else {
		printf("\nEnter elements: ");
		int i = 0, sum = 0, num = n;
		while (num > 0) {
			// as 'arr + i' is pointing to address so no need of '&'
			scanf("%d", arr + i);
			sum += *(arr + i);
			i++; num--;
		}
		// displaying inserted elements
		printf("\nInserted elements are: ");
		for (i = 0; i < n; i++) {
			printf("\n%d", *(arr + i));
		}
		printf("\nSum of the inserted elements: %d", sum);
	}
	// deallocating array
	free(arr);
	return 0;
}
