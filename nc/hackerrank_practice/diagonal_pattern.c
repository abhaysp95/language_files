/*** Diagonal pattern printing program ***/

#include<stdio.h>


int main(int argc, char *argv[]){
	int n,i,j,k,l;
	printf("\nEnter the number: ");
	scanf("%d",&n);
	// for the upper part
	for (i = 0; i < n; i++) {
		// for the first triangle
		for (j = 0; j < i; j++) {
			printf("%d",n-j);
		}
		// for the mid triangle
		for (k = 0; k < (2*(n-i))-1; k++) {
			printf("%d",n-i);
		}
		// for the last triangle
		for (l = 0; l < i; l++) {
			printf("%d",n-i+l+1);
		}
		printf("\n");
	}

	// for the bottom part
	for (i = 1; i < n; i++) {
		// for the first triangle
		for (j = 0; j < n-i; j++) {
			printf("%d",n-j);
		}
		// for the mid triangle
		for (k = 0; k < (2*i)-1; k++) {
			printf("%d",i+1);
		}
		// for the last triangle
		for (l = 0; l < n-i; l++) {
			printf("%d",n-j+l+1);
		}
		printf("\n");
	}
	return 0;
}



