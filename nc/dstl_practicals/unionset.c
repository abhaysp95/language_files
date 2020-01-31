/*** Program to create to set and implement union on them ***/

#include<stdio.h>
#define size 15

void union(int a[], int b[], int , int );

int x,y,i,j;
int a[size],b[size],c[size];
int main(int argc, char *argv[])
{
	printf("\nEnter the cardinality for first set- ");
	scanf("%d",&x);
	printf("\nEnter the cardinality of second set- ");
	scanf("%d",&y);
	printf("\nEnter the elements of first set- ");
	for(i=0;i<x;i++)
	{
		printf("\n%d: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\nEnter the elements of second set- ");
	for(i=0;i<y;i++)
	{
		printf("\n%d: ",i+1);
		scanf("%d",&b[i]);
	}
	union(a,b,x,y);
	return 0;
}

void union(int a[], int b[], int p, int q)
{
	int k;
	for(i=0;i<p;i++)
	{
		c[i]=a[i];
	}
	for(j=0;j<q;j++)
	{
		for(k=0;k<i;k++)
		{
			if(b[j]!=c[k])
			{
				c[i]=b[j];
				i++;
			}
		}
	}
	printf("\nunion is- ");
	for(k=0;k<i;k++)
	{
		printf("\n%d: %d",k+1,c[k]);
	}
}

