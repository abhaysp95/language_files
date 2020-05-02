/** Name -> Abhay Shanker Pathak
Date -> 2020-05-01
Description -> Printing Fibonnaci number for the given sequence number
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-05-01 */


#include<stdio.h>

// prototype <<<
int get_fib_num(int );
// >>>

// function for getting fibonacci number <<<
int get_fib_num(int position) {
	// if (position == 0 || position == 1) {
	if (position < 3) {
		return 1;	// this condition is called base case
	}
	// below condition is called recursive case
	return get_fib_num(position - 1) + get_fib_num(position - 2);
}
// >>>

// main function <<<
int main(int argc, char* argv[]) {
	int pos;
	printf("Enter the position: ");
	scanf_s("%d", &pos, sizeof(pos));
	int result = get_fib_num(pos);
	printf("Result is: %d", result);
	return 0;
}
// >>>
