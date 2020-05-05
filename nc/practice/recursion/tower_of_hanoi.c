/** Name -> Abhay Shanker Pathak
Date -> 2020-05-05
Description -> recursion problem, tower of hanoi
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-05-05 */


#include<stdio.h>

int TOH(int ,char ,char ,char);

static int count = 0;

// main function
// <<<
int main(int argc, char* argv[]) {
	int disk_count, cycle;
	char first='a', second='b', third='c';
	printf("Enter the number of disks: ");
	scanf("%d", &disk_count);
	cycle = TOH(disk_count, first, second, third);
	printf("Total number of cycles: %d\n", cycle);
	return 0;
}
// >>>

// function for tower of hanoi
// <<<
int TOH(int num, char a, char b, char c) {
	if (num > 0) {
		TOH(num - 1, a, c, b);
		printf("Moving last disk from %c to %c\n", a, c);
		count += 1;
		TOH(num - 1, b, a, c);
	}
	return count;
}
// >>>
