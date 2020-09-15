/** Name -> Abhay Shanker Pathak
Date -> 2020-04-05
Description -> just an example
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-04-05 */

#include<stdio.h>
#include<stdlib.h>

// main function <<<
int main(int argc, char *argv[]){
	int arr[3][3]      = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int (*ptr2element) = &(arr[0][0]);
	int (*ptr2arrRow)[3] = &(arr[0]);
	/* int *(*(ptr2arrRow + 0)) = &(arr[0]); */
	int (*ptr2array)[3][3] = &(arr);

	printf("The element is '%d' and at address '%p'\n", *ptr2element, ptr2element);
	ptr2element++;
	printf("The element is '%d' and at address '%p'\n", *ptr2element, ptr2element);

	printf("The element is '%d' and at address '%p'\n", **ptr2arrRow, ptr2arrRow);
	ptr2arrRow++;
	printf("The element is '%d' and at address '%p'\n", **ptr2arrRow, ptr2arrRow);

	printf("The element is '%d' and at address '%p'\n", ***ptr2array, ptr2array);
	ptr2array++;
	printf("No element at address '%p'. The pointer is out of bounds\n", ptr2array);
	return 0;
}
// >>>
