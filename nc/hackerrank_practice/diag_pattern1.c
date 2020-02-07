/** Name -> Abhay Shanker Pathak
Date -> 2020-02-07
Description -> printing reverse triangle
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-07 */

#include<stdio.h>


int main(int argc, char *argv[]){
	int i,j,k;
	for (i = 0; i <=5; ++i) {
		for(j=0; j<5-i; j++){
			printf(" ");
		}
		for (k = 0; k < i; ++k) {
			printf("*")	;
		}
		printf("\n");
	}
	return 0;
}


