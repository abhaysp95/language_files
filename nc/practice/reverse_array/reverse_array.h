// reverse the array, get the address of the array and reverse array
// this is test whether a function of void type can work here or not and work
// with addresses, don't wan't to make a new array to do something like
// new_array = array_from_here

void reverse_array(int *array, int size) {
	for (int i = 0; i < size / 2; ++i) {
		*(array + i) = *(array + i) + *(array + size - 1 -i);
		*(array + size - 1 -i) = *(array + i) - *(array + size - 1 - i);
		*(array + i) = *(array + i) - *(array + size - 1 - i);
	}
}
