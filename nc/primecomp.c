/***Program to determine the number to be prime or composite***/

#include<stdio.h>

int main(int argc, char *argv[]) {
	int n,i,flag=0;;
	printf("\nEnter the number - ");
	scanf("%d",&n);
	for (i=2;i<n;i++)
	{
		if(n%i==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("\n%d is composite number.",n);
	else
		printf("\n%d is prime number.",n);
	return 0;
}
