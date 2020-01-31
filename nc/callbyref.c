/***program to test a function by call by reference method***/

#include<stdio.h>

void inc(int *);

int main(int argc, char *argv[])
{
	int num=2;
	printf("\nValue before the function is called - %d",num);
	printf("\nAddress of num is %d",&num);
	inc(&num);
	printf("\nValue after the function is called - %d",num);
	return 0;
}

void inc(int *n)
{
	int x=*n,y=n;
	printf("\nx is %d",x);
	printf("\ny is %d",y);
	*n=*n+10;
	x=x+10;
	y=y+10;
	printf("\nNow x is %d",x);
	printf("\nNow y is %d",y);
	printf("\nNow n is %d",n);
	printf("\nNow *n is %d",*n);
}
