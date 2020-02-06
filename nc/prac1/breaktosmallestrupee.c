/** Name -> Abhay Shanker Pathak
Date -> 2020-02-06
Description -> Break the amount to smallest possible number of bank notes
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-06 */

#include<stdio.h>


int main(int argc, char *argv[]){
	int amount;
	printf("\nEnter the amount: ");
	scanf("%d",&amount);
	if (amount > 0) {
		if (amount >= 2000) {
			printf("\n%d Note(s) of 2000",amount/2000);
			amount = amount%2000;
		}
		if (amount >= 500) {
			printf("\n%d Note(s) of 500",amount/500);
			amount = amount%500;
		}
		if (amount >= 100) {
			printf("\n%d Note(s) of 100",amount/100);
			amount = amount%100;
		}
		if (amount >= 50) {
			printf("\n%d Note(s) of 50",amount/50);
			amount = amount%50;
		}
		if (amount >= 20) {
			printf("\n%d Note(s) of 20",amount/20);
			amount = amount%20;
		}
		if (amount >= 10) {
			printf("\n%d Note(s) of 10",amount/10);
			amount = amount%10;
		}
		if (amount >= 5) {
			printf("\n%d Note(s) of 5",amount/5);
			amount = amount%5;
		}
		if (amount >= 2) {
			printf("\n%d Note(s) of 2",amount/2);
			amount = amount%2;
		}
		if (amount >= 1) {
			printf("\n%d Note(s) of 1",amount/1);
			amount = amount%1;
		}
	}
	else
		printf("\nEnter amount correctlly!");
	return 0;
}


