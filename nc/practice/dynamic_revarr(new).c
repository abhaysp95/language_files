/** Name -> Abhay Shanker Pathak
Date -> 2020-02-23
Description -> Reversing the array(created dynamically)
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-23 */

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	int *arr1;
	int num, i;
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
	// reversing logic
	int temp;
	for (i = 0; i < num/2; i++) {
		// let if arr = 1000(pointing a block), then arr + 1 doesn't mean 1001 it means next block to 1000,
		//which can be 1002 or 1004(dataype = int(compiler dependent))
		temp = (int)*(arr1 + num -i - 1);
		*(arr1 + num -i - 1) = *(arr1 + i);
		*(arr1 + i) = temp;
	}
	printf("\nReverse order is: ");
	for (i = 0; i < num; i++) {
		printf("\n%d", *(arr1 + i));
	}
	free(arr1);
	return 0;
}
