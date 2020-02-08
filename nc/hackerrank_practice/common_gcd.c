/** Name -> Abhay Shanker Pathak
Date -> 2020-02-08
Description -> Find Greatest common factor of two numbers
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-08 */

#include<stdio.h>
#define size 50

int main(int argc, char *argv[]){
	int num1, num2, a[size],i,j,k;
	printf("Enter the two numbers: ");
	scanf("%d%d",&num1,&num2);
	if ((num1 < 10000 && num1 > 1) && (num2 < 10000 && num2 > 1)) {
		/* for (i = 1,j=0; i < num1/2; ++i,++j) { */
		/* 		if (num1%i == 0) { */
		/* 				a[j] = num1/i; */
		/* 			} */
		/* 	} */
		/* printf ("\nFirst array: "); */
		/* for (k=0; k < j; k++) { */
		/* 	printf("%d\n",a[k]); */
		/* } */
		j = 0;
		for (i = 1; i <=num1 && i <=num2; i++) {
			if ( num1%i == 0 && num2%i == 0) {
				a[j] = i;
				j++;
			}
		}
		printf ("\nFirst array: ");
		for (k=0; k < j; k++) {
			printf("%d\n",a[k]);
		}

		printf("GCD is %d",a[j-1]);
	}
	return 0;
}



