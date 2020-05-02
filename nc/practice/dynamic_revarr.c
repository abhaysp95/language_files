/** Name -> Abhay Shanker Pathak
Date -> 2020-02-23
Description -> Reversing the array(created dynamically)
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-23 */

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	int *arr1, *arr2;
	int num, i, j;
	printf("\nEnter the limit: ");
	scanf("%d", &num);
	arr1 = (int *)malloc(num*sizeof(int));
	if (arr1 == NULL) {
		printf("\nMemory not allocated, Exiting");
		exit (0);
	}
	else {
		printf("\nEnter the elements: ");
		for (i = 0; i < num; i++) {
			printf("\n%d: ", i + 1);
			scanf("%d", arr1 + i);
		}
	}
	// reversing the array
	printf("\nReverse order is: ");
	arr2 = (int *)malloc(num*sizeof(int));
	for (i = num - 1, j = 0; i >= 0; i--, j++) {
		*(arr2 + j) = *(arr1 + i);
		printf("\n%d", *(arr2 + j));
	}
	free(arr1);
	free(arr2);
	return 0;
}
