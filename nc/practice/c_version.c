/** Name -> Abhay Shanker Pathak
Date -> 2020-02-06
Description -> Know c - version
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-06 */

#include<stdio.h>


int main(int argc, char *argv[]){
#if __STDC_VERSION__ >= 201710L
	printf("using C18!\n");
#elif __STDC_VERSION__ >= 201112L
	printf("using C11!\n");
#elif __STDC_VERSION__ >= 199901L
	printf("using C99!\n");
#else
	printf("using C89/C90!\n");
#endif
	return 0;
}

