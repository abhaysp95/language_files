/** Name -> Abhay Shanker Pathak
Date -> 2020-02-07
Description -> Another pattern printing
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-07 */

#include<stdio.h>


int main(int argc, char *argv[]){
	int n,i,j,k;
	printf("Enter the number: ");
	scanf("%d",&n);
	for (i = n; i >=0 ; i--) {
		for (j = 0; j < i; ++j) {
				printf(" ");
		}
		for (k = 0 ;k < n-i; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

