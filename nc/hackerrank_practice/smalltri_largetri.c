/** Name -> Abhay Shanker Pathak
Date -> 2020-02-09
Description -> Given n triangles, their sides a, b, c. Print in same style but sorted from smallest to largest
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-09 */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define size 50

void sort_by_area(int *arr1, int (*arr)[3], int n);

int main(int argc, char *argv[]){
	int n, a, b, c, i, j, p;
	int arr[size][3], arr1[size];
	printf("\nEnter the number of triangles: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d: ",j+1);
			scanf("%d", &arr[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++) {
		j = 0;
		a = arr[i][j];
		b = arr[i][j+1];
		c = arr[i][j+2];
		p = (a + b + c)/2;
		arr1[i] = abs(sqrt(p * (p - a) * (p - b) * (p - c)));
	}
	for (i = 0; i < n; i++) {
		printf("\nArea of %d triangle: %d",i+1,arr1[i]);
	}
	sort_by_area(arr1, arr, n);
	return 0;
}

void sort_by_area(int *arr1, int (*arr)[3], int n) {
	int i, j, arr2[size], temp, d;
	/* printf("\n"); */
	/* for (i = 0; i < 3; i++) { */
	/* 	printf("%d\n",arr[1][i]); */
	/* } */
	/* for (i = 0; i < n; i++) { */
	/* 	printf("Area of %d triangle: %d\n",i+1,arr1[i]); */
	/* } */

	/* for (i = 0; i < n; i++) { */
	/* 	for (j = 0; j < 3; j++) { */
	/* 		printf("%d arm of %d triangle: %d\n",j , i, arr[i][j]); */
	/* 	} */
	/* 	printf("\n"); */
	/* } */
	// now arr2 is having the areas of triangles
	for (i = 0; i < n; i++) {
		arr2[i] = arr1[i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n-i; j++) {
			if (arr2[j] > arr2[j+1])	{
				temp = arr2[j];
				arr2[j] = arr2[j+1];
				arr2[j+1] = temp;
			}
		}
	}
	// now checking if the areas stored in arr2 are sorted
	/* for (i = 0; i < n; i++) { */
	/* 	printf("\n%d",arr2[i]); */
	/* } */
	/* printf("\n"); */
	for (i = 0; i < n; i++ ) {
		for (j = 0; j < 3; j++) {
			d = 0;
			if(arr2[i] == arr1[j]){
				d = j;
				/* printf("\n%d",d); */
			}
		}
		printf("\n");
		for (j = 0; j < 3; j++) {
			printf("%d ",arr[d][j]);
		}
		printf("\n");
	}
}
