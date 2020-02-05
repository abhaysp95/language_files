/*** Diagonal pattern printing program ***/

#include<stdio.h>


int main(int argc, char *argv[]){
	int n,i,j,k;
	printf("\nEnter the number: ");
	scanf("%d",&n);
	for (i = 0; i < ((2*n)-1); ++i) {
		for (j = 0; j < (((2*n)-1)-i); ++j) {
			/* if(i>0){ */
			/* 	if(j==0){ */
			/* 		printf("%d",n); */
			/* 	} */
			/* 	else if (j>0){ */
			/* 		printf("%d",n-j); */
			/* 	} */
			/* } */
			/* else */
			/* 	printf("%d",n); */
			if (j==0) {
				printf("%d",n);
			}
			else if (j>0) {
				if (j>=i) {
					printf("%d",n-i);
				}
				else
					printf("%d",n-j);
			}
		}
		if (i!=0) {
			for (k = 0; k < i; ++k) {
				/* if (k==((2*n)-2)) { */
				/* 	printf("%d",n); */
				/* } */
				/* else */
				/* printf("%d",n-k); */
				printf("%d",j+k-1);
			}
		}
		printf("\n");
	}
	return 0;
}



