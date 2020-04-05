/** Name -> Abhay Shanker Pathak
Date -> 2020-04-03
Description -> detect whether a number is happy number or not
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-04-03 */


// description -----------------------------------------------------

/* A happy number is a number whose digits square should result to 1
   If not results to 1, then that num becomes the sum of the square of it's digit and should again become to 1
Ex:-
Input: 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2= 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1 */

#include<stdio.h>
#include<math.h>
#define FOREVER for(;;)

// main function <<<
int main(int argc, char *argv[]){
	int num, r, new_num = 0, backup;
	printf("Enter the number: ");
	scanf("%d", &num);
	backup = num;
	FOREVER {
		new_num = 0;
		while (num > 0) {
			r = num % 10;
			num = num / 10;
			new_num = new_num + pow(r, 2);
		}
		if (new_num == 1) {
			printf("\nEntered number %d is happy number.", backup);
			break;
		}
		else {
			num = new_num;
		}
	}
	return 0;
}
// >>>
