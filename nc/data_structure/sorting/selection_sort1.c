/**
    _    ____  ____
   / \  / ___||  _ \   Abhay Shanker Pathak
  / _ \ \___ \| |_) |  abhaysp9955@gmail.com
 / ___ \ ___) |  __/   https://github.com/coolabhays
/_/   \_\____/|_|

selection sort with array */


#include<stdio.h>
#define size 12

int get_min_addr(int *arr, int ,int );
void min_swap(int *arr, int ,int );

// main function
int main(int argc, char* argv[]) {
	int arr[size], i = 0, flag = 0;
	char val[size];
	printf("Enter the elements, to stop enter 'q'\n");
	while (1) {
		fgets(val, sizeof(val), stdin);
		if (val[0] == 'q') {
			break;
		}
		if (sscanf(val, "%d", &arr[i]) == 1) {
			i++;
		}
	}
	printf("You entered following elements: \n");
	int arr_len = i;
	for (int j = 0; j < arr_len; ++j) {
		printf("%d\t", arr[j]);
	}
	printf("\n");

	for (int j = 0; j < arr_len - 1; j++) {
		int min_addr = get_min_addr(arr, j, arr_len);
		min_swap(arr, j, min_addr);
	}

	printf("Sorted array is: \n");
	for (int j = 0; j < arr_len; j++) {
		printf("%d\t", arr[j]);
	}
	printf("\n");
	return 0;
}

// function to get address of minimum value
int get_min_addr(int *arr, int initial, int arr_len) {
	int loc = initial;
	initial++;
	while (initial < arr_len) {
		if (arr[loc] > arr[initial]) {
			loc = initial;
		}
		initial++;
	}
	printf("loc is %d\n", loc);
	return loc;
}

// function to swap minimum value with current intial value
void min_swap(int *arr, int initial, int loc) {
	if (arr[loc] != arr[initial]) {
		arr[loc] = arr[loc] + arr[initial];
		arr[initial] = arr[loc] - arr[initial];
		arr[loc] = arr[loc] - arr[initial];
	}
}

// things which are not in use
	// while (1) {
	// 	scanf("%d", &val);
	// 	if (val == 'q') {
	// 		break;
	// 	}
	// 	arr[i] = val;
	// 	i++;
	// }

	// printf(val);
	// int arr_len = sizeof(arr) / sizeof(arr[0]);
	// printf("length is %d\n", arr_len);

	// if (val == NULL) {
	// 	break;
	// }
