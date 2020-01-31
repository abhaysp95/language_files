#include<stdio.h>
#define size 10

void Max(int a[], int );

int j=0;
int main(int argc, char *argv[]){
	int a[size],n,i;
	printf("\nEnter the count for numbers: ");
	scanf("%d",&n);
	printf("\nEnter the elements in array: ");
	for (i = 0; i < n; ++i) {
		printf("\n%d: ",i+1);
		scanf("%d",&a[i]);
	}
	Max(a,n);
	return 0;
}

void Max(int a[], int n){
	int max;
	max=a[0];
	if(j<n){
		if(max<a[j]){
			max=a[j];
		}
	}
	j++;
	Max(a,n);
}
