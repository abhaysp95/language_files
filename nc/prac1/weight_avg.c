/** Name -> Abhay Shanker Pathak
Date -> 2020-02-06
Description -> average of item's weight
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-06 */

#include<stdio.h>


int main(int argc, char *argv[]){
	float  w_item1,w_item2,avg;
	int n1,n2;
	printf("\nEnter the weight of first item: ");
	scanf("%f",&w_item1);
	printf("\nEnter the no. of first type item: ");
	scanf("%d",&n1);
	printf("\nEnter the weight of second item: ");
	scanf("%f",&w_item2);
	printf("\nEnter the no. of second type item: ");
	scanf("%d",&n2);
	avg = ((w_item1*n1)+(w_item2*n2))/2;
	printf("\nTotal average is: %f",avg);
	return 0;
}



