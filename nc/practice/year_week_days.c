/** Name -> Abhay Shanker Pathak
Date -> 2020-02-06
Description -> Program to change given days into years weaks and days
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-06 */

#include<stdio.h>


int main(int argc, char *argv[]){
	int given_days,years,weeks,days;
	printf("\nEnter the number of days: ");
	scanf("%d",&given_days);
	// no concept of leap year here
	years = given_days/365;
	if (given_days%365 > 6) {
		weeks = ((given_days%365)/7);
		if (weeks > 0) {
			days = ((given_days%365)%7);
		}
	}
	else
		days = (given_days%365);
	printf("\nYears: %d",years);
	printf("\nWeeks: %d",weeks);
	printf("\nDays: %d",days);
	return 0;
}


