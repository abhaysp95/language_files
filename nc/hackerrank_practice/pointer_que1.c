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
	int arr[size], n, i;
	int *p;
	scanf("%d", &n);
	p = arr;
	for (i = 0; i < n; i++) {
		scanf("%d",p);
		p = p + 1;	// p is increasing in terms of size of int like 100 to 102
	}
	p = arr;
	for (i = 0; i < n; i++) {
		printf("%d\n", *p);
		p = p + 1;
	}
	return 0;
}
