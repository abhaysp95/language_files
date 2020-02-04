/*** Find second largest value with only one loop ***/

#include<stdio.h>
#define size 15

int main(int argc, char *argv[]){
	int n,i,max,sec,a[size],j;
	printf("\nEnter the number of elements to enter in array: ");
	scanf("%d",&n);
	printf("\nEnter the elements in the array: ");
	for (i = 0; i < n; ++i) {
		printf("\n%d:",i+1);
		scanf("%d",&a[i]);
	}
	sec = max = a[0];
	for (i = 1; i < n; ++i) {
		if (a[0] < a[i]) {
				sec = max;
				max = a[i];
				j = i;
			}
		else if (sec < a[i] && max != a[i]) {
				sec = a[i];
				/* c = i; */
		}
	}
	for (i = 0; i < n; ++i) {
		if (a[i] == sec ) {
			break;
			}
	}
	printf("\nPosition printed according to index number.");
	printf("\nLargest element is %d in position %d. \nSecond largest element is %d in %d position",max,j,sec,i);
	return 0;
}



