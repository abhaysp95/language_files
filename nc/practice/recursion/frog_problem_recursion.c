/** Name -> Abhay Shanker Pathak
Date -> 2020-05-01
Description -> frog problem with recursion, frog can hop either 1 feet or 2 feet at a time
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-05-01 */


#include<stdio.h>

// function to get count <<<
int get_total_count(int stone_count) {
	// if (stone_count <= 2) {
	// 	return 1;
	// }
	if (stone_count <= 1) {
		return stone_count + 1;
	}
	return get_total_count(stone_count - 1) + get_total_count(stone_count - 2);
}
// >>>

// main function <<<
int main(int argc, char* argv[]) {
	int stone_count;
	printf("Enter the stone_count: ");
	scanf("%d", &stone_count);

	int result = get_total_count(stone_count);
	printf("Result is: %d", result);
	return 0;
}
// >>>
