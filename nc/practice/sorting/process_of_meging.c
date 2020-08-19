// show the process of merging of two sorted array into third one

// now, if two list are already sorted then resultant will be sorted


#include <stdio.h>
#define FLENGTH 5
#define SLENGTH 6
#define TLENGTH (FLENGTH + SLENGTH)
// #define MIN(a,b) (a > b ? b : a)  not needed

int *merge_arrays(int *, int *);

int *merge_arrays(int *farray, int *sarray) {
	static int tarray[TLENGTH];  // static is necessary else this array will not exist outside of this functions scope
	int i = 0, j = 0, k = 0;
	for (i = 0, j = 0, k = 0; j < FLENGTH && k < SLENGTH; ++i) {
		int fkey = *(farray + j);
		int skey = *(sarray + k);

		// move the position with minimum
		if (fkey < skey) {
			*(tarray + i) = fkey;
			++j;
		}
		else {
			*(tarray + i) = skey;
			++k;
		}
	}

	// copy the left element from one of the left array
	if (j < FLENGTH) {
		while (i < TLENGTH) {
			*(tarray + i) = *(farray + j);
			++i;
			++j;
		}
	}
	else {
		while (i < TLENGTH) {
			*(tarray + i) = *(sarray + k);
			++i;
			++k;
		}
	}
	return tarray;
}

int main(int argc, char **argv) {
	int first_array[FLENGTH] = {2, 8, 15, 18, 19};
	int second_array[SLENGTH] = {4, 5, 9, 12, 17, 20};
	int *third_array;

	third_array = merge_arrays(first_array, second_array);

	// print till MIN
	for (int i = 0; i < TLENGTH; ++i) {
		printf("%d\n", *(third_array + i));
	}
	return 0;
}
