/** Name -> Abhay Shanker Pathak
Date -> 2020-02-13
Description -> A program to test debugging
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-13 */

#include<stdio.h>


int main(int argc, char *argv[]){
	int fact=0, i, n;
	printf("\nEnter the number: ");
	scanf("%d",&n);
	for (i=1;i <= n; i++) {
		fact=fact*i;
	}
	printf("The factorial of %d is %d\n",n,i);
	return 0;
}
