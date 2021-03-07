// main file

#include <iostream>

struct demo_obj {
	float x, y, z;
	demo_obj(): x(10), y(20), z(30) {};
};

int main(int argc, char **argv) {
	/** stack */
	int value = 5;
	int array[5];
	array[0] = 5;
	array[1] = 4;
	array[2] = 3;
	array[3] = 2;
	array[4] = 1;
	demo_obj d1;

	/** heap */
	int* val = new int;
	*val = 5;
	int* arr = new int[5];
	arr[0] = 5;
	arr[1] = 4;
	arr[2] = 3;
	arr[3] = 2;
	arr[4] = 1;
	demo_obj* d2 = new demo_obj();
	delete val;
	delete[] arr;
	delete d2;
	return 0;
}