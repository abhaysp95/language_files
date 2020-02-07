/** Name -> Abhay Shanker Pathak
Date -> 2020-02-07
Description -> More complex pattern
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-07 */

#include<stdio.h>


int main(int argc, char *argv[]){
	int i,j,k,l,n;
	printf("Enter the number :\n");
	scanf("%d",&n);
	for (i = 0; i < n; ++i) {
		for(j = 0; j < n-i-1; ++j) {
			printf(" ");
		}
		for (k = 0; k <= i; k++) {
			printf("%d",k+1);
		}
		for (l = i-1; l >= 0; l--) {
			printf("%d",l+1);
		}
		printf("\n");
	}
	for (i = n-1; i >=0 ; i--) {
		for (j = 0; j<n-i; j++) {
			printf(" ");
		}
		for (k = 0; k < i; k++) {
			printf("%d",k+1);
		}
		for (l=i-1; l > 0; l--) {
			printf("%d",l);
		}
		printf("\n");
	}
	return 0;
}


