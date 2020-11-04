#include <stdio.h>
#include "../inc/util.h"

// get max number
int max(int *arr) {
	int max = *arr;
	for (int i = 0; i < SIZE; ++i) {
		if (max < *(arr + i)) {
			max = *(arr + i);
		}
	}
	return max;
}

// get min number
int min(int *arr) {
	int min = *arr;
	for (int i = 0; i < SIZE; ++i) {
		if (min > *(arr + i)) {
			min = *(arr + i);
		}
	}
	return min;
}

// actual count sort function
/*******************************************************/

int *sort(int *arr, int *newarr) {
	int k = max(arr);
	int temp[k + 1];

	int i = 0;
	// inclusive range
	while (i <= k) {
		*(temp + i++) = 0;
	}

	// store the count of each element
	i = 0;
	while (i < SIZE) {
          // fill in the count of each element of arr to the position which is
          // equal to the value of element of arr
          /* like if 3 comes 2 times in arr, then temp[3] = 2 */
          *(temp + *(arr + i++)) += 1;
	}

	// store the cummulative sum of the elements of temp array
	i = 1;
	while (i <= k) {
		*(temp + i) += *(temp + (i - 1));
		i++;
	}

	// find index of each element of orignal array in the temp array and place the elements in the newarr
	i = SIZE - 1;
	while (i >= 0) {
		*(newarr + *(temp + *(arr + i)) - 1) = *(arr + i);
		*(temp + *(arr + i)) -= 1;
		i--;
	}
	return newarr;
}

/*******************************************************/


void print(int *arr) {
	for (int i = 0; i < SIZE; ++i) {
		printf("%d\n", *(arr + i));
	}
}
