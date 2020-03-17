/** Name -> Abhay Shanker Pathak
Date -> 2020-03-16
Description -> Character counting
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-16 */

#include<stdio.h>


// main function <<<
int main(int argc, char *argv[]){
	long count;

	count = 0;
	while (getchar() != EOF)
		++count;
	printf("%ld", count);
	return 0;
}
// >>>
