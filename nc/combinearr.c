/* merge two arrays in ascending order in third array */

#include<stdio.h>
#define size 20

void sorta(int a[], int );
void sortb(int b[], int );

int i,j,k,m,n,temp;

int main() {
	int a[size],b[size],c[size],x,y;
	printf("\nEnter the number of integers for first array- ");
	scanf("%d",&m);
	printf("\nEnter the number of integers for second array- ");
	scanf("%d",&n);
	printf("\nEnter the elements in first array- ");
	/* entering elements */
	for(i=0;i<m;i++) {
		printf("\n%d: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\nEnter the elements in second array- ");
	/* entering elements */
	for(i=0;i<n;i++) {
		printf("\n%d: ",i+1);
		scanf("%d",&b[i]);
	}
	sorta(a,m);
	sortb(b,m);
	for(i=0;i<m;i++) {
		printf("\n%d",a[i]);
	}
	for(i=0;i<n;i++) {
		printf("\n%d",b[i]);
	}
	return 0;
}

void sorta(int a[], int m) {
	for(i=0;i<m;i++) {
		for(j=0;j<m-i;j++) {
			if(a[j]>a[j+1]) {
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=a[j];
			}
		}
	}
	for(i=0;i<m;i++) {
		printf("\n%d",a[i]);
	}
}

void sortb(int b[], int n) {
	for(i=0;i<n;i++) {
		for(j=0;j<n-i;j++) {
			if(b[j]>b[j+1]) {
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=b[j];
			}
		}
	}
	for(i=0;i<n;i++) {
		printf("\n%d",b[i]);
	}
}
