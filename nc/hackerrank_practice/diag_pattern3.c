/** Name -> Abhay Shanker Pathak
Date -> 2020-02-07
Description -> Another pattern printing
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-07 */

#include<stdio.h>


int main(int argc, char *argv[]){
	int n,i,j,k,l;
	printf("Enter the number: ");
	scanf("%d",&n);
	for (i = n; i >0 ; i--) {
		for (j = 0; j < n-i; ++j) {
				printf(" ");
		}
		for (k = 0 ;k < i; k++) {
			printf("*");
		}
		for (l = 0; l < i-1; l++) {
			printf("*");
		}
		printf("\n");
	}
	for (i = n-1; i > 0; i--) {
		for (j = 0; j < i-1; j++) {
			printf(" ");
		}
		for (k = 0; k <= n-i; k++) {
			printf("*");
		}
		for (l = 0; l < n-i; l++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

