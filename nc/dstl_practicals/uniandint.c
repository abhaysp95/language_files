/*** Program to implement union and intersection in two sets ***/

#include<stdio.h>
#define size 15

int main(int argc, char *argv[])
{
	int a[size],b[size],m,n,ch;
	print("\nEnter the cardinality of first set- ");
	scanf("%d",&m);
	printf("\nEnter the cardinality of second set- ");
	scanf("%d",&n);
	printf("\nEnter the elements for first set");
	for(int i=0;i<m;i++)
	{
		printf("\n%d: ",i+1);
		scanf("%d",a[i]);
	}
	printf("\nEnter the elements for second set");
	for(int i=0;i<n;i++)
	{
		printf("\n%d: ",i+1);
		scanf("%d",b[i]);
	}
	printf("\n***1: UNION***");
	printf("\n***2: INTERSECTION***");
	printf("\n***3: Exit***");
	printf("\nEnter the choice- ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			Union(a,b,m,n);
			break;
		case 2:
			Intersection(a,b,m,n);
			break;
	}
	return 0;
}

void Union(int a[], int b[], int m, int n)
{
	int c[size],i,j,k,flag=0;
	for(i=0,k=0;i<m;i++,k++)
	{
		c[k]=a[i];
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<m;j++)
		{
			if(b[i]==c[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			c[k]=b[i];
			k++;
		}
	}
	printf("\nUnion set is- ");
	for(i=0;i<k;i++)
	{
		printf("\n%d: %d",i+1,c[k]);
	}
}

void Intersection(int a[], int b[], int m, int n)
{
	int c[size],i,j,k,flag=0;
	for(i=0;i<m;i++)
	{
		flag=0;
		for(j=0;j<n;j++)
		{
			if(a[i]==b[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			c[k]=a[i];
			k++;
		}
	}
	if(k==0)
		printf("\nNo intersection.");
	else
	{
		printf("\nIntersection set is- ");
		for(i=0;i<k;i++)
		{
			printf("\n%d: %d",i+1,c[i]);
		}
	}
}

