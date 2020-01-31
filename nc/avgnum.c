/***find average of first n number***/

#include<stdio.h>

int main() {
	int i=0,n,sum=0;
	float avg;
	printf("\nEnter the value of n- ");
	scanf("%d",&n);
	do {
		sum = sum+i;
		i++;
	}while(i<=n);
	avg=(float)sum/n;
	printf("\nSum is - %d",sum);
	printf("\nAverage number is - %.2f",avg);
	return 0;
}
