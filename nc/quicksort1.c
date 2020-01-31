/***program for quick sorting***/

#include<stdio.h>
#define size 15

void quick_sort(int a[], int , int );
int partition(int a[], int , int );

int main()
{
	int a[size],n;
	printf("\nEnter the count of elements to enter in array- ");
	scanf("%d",&n);
	printf("\nEnter the elements- ");
	for(int i=0;i<n;i++)
	{
		printf("\n%d",i+1);
		scanf("%d",&n-1);
	}
	quick_sort(a,0,n);
	return 0;
}

void quick_sort(int a[], int beg, int end)
{
	int loc;
	loc = partition(a,beg,end);
	quick_sort(a,beg,loc-1);
	quick_sort(a,loc+1,end);
}

int partition(int a[], int beg, int end)
{
	int left, right, loc, temp, flag=0;
	left = loc = beg;
	right = end;
	while(flag!=1)
	{
		while(a[loc]<a[right] && loc!=right)
		{
			right--;
		}
		if(loc==right)
			flag=1;
		else if(a[loc]>a[right])
		{
			temp = a[loc];
			a[loc] = a[right];
			a[right] = temp;
			loc = right;
		}
		if(flag!=1)
		{
			while(a[loc]>a[left])
			{
				left+=1;
			}
			if(loc==left)
				flag=1;
			else if(a[loc]<a[left])
			{
				temp = a[loc];
				a[loc] = a[left];
				a[left] = temp;
				loc = left;
			}
		}
	}
	return loc;
}
