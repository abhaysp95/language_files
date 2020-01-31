/**program to test function by call by value**/

#include<stdio.h>

int inc(int );

int main(int argc, int *argv[])
{
	int num=2,n1;
	printf("\nNumber before func is called - %d ",num);
	n1=inc(num);
	printf("\nNumber after func is called - %d ",num);
	printf("\nNumber after return func is called - %d ",n1);
	return 0;
}

int inc(int n)
{
	n=n+10;
	printf("\nNumber during func is called - %d ",n);
	return n;
}
