/** Name -> Abhay Shanker Pathak
Date -> 2020-02-14
Description -> Program to store n elements in array and print them using pointer
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-14 */

#include<stdio.h>
#define size 100

void print(int *, int );

int main(int argc, char *argv[]){
	int arr[size], i, n;
	printf("\nEnter the numbers: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	print(arr, n);
	return 0;
}

void print(int *arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d",arr[i]);
	}
}
