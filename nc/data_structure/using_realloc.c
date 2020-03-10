/** Name -> Abhay Shanker Pathak
Date -> 2020-03-10
Description -> Learining to use realloc
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-10 */

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	int n1;
	printf("\nEnter size first time: ");
	scanf("%d", &n1);
	int *ptr = (int *)malloc(n1 * sizeof(int));

	printf("\nAddress of memory allocated first time: ");
	for (int i = 0; i < n1; i++)
		// %p is used to print pointers address(gives in hex)
		printf("\n%d: %p\t%u", i + 1, ptr + i, ptr + i);

	int n2;
	printf("\nEnter size second time: ");
	scanf("%d", &n2);
	ptr = realloc(ptr, n2 * sizeof(int));

	printf("\nAddress of memory allocated second time: ");
	for (int i = 0; i < n2; i++)
		printf("\n%d: %p\t%u", i + 1, ptr + i, ptr + i);
	return 0;
}
