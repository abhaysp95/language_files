/** Name -> Abhay Shanker Pathak
Date -> 2020-02-06
Description -> Distance between two co-ordinates
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-06 */

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
	int x1,y1,x2,y2;
	float distance;
	printf("\nEnter intial co-ordinate then final co-ordinate: ");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	/* printf("%lf",pow(4,5)); */
	distance = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
	printf("%lf",distance);
	return 0;
}
