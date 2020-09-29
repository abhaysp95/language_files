/* prgoram for count sort */

/* some inputs can be: {3, 0, 4, 0, 2, 9, 0, 5}
   {8, 2, 9, 9, 0, 7, 0, 1, 4, 5}
*/

#include <stdio.h>
#include "util.h"

int main(int argc, char **argv) {
	int arr[SIZE] = {3, 0, 4, 0, 2, 9, 0, 5};

	puts("Printing array before sort:");
	print(arr);

	int *sorted_arr;
	sorted_arr = sort(arr, sorted_arr);

	puts("Printing array after sort:");
	print(sorted_arr);
	return 0;
}
