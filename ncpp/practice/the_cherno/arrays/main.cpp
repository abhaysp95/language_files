#include <iostream>
#include <array>

class Entity {
	public:
		// now there's no method to get the size of our old styled array, one way is "sizeof(array) / sizeof(type)"
		static const int exampleSize = 5;
		int arr[exampleSize];
		Entity() {
			for (int i = 0; i < 5; ++i) {
				*(arr + i) = 12;
			}
		}
};

class Entity1 {
	public:
		int* arr = new int[5];
		Entity1() {
			for (int i = 0; i < 5; ++i) {
				*(arr + i) = 12;
			}
		}
};

int main(int argc, char **argv) {
	int arr[5];  // this will be alive only to this scope(it's in stack)
	int *ptr = arr;
	//for (int i = 0; i < 5; ++i) {
		//*(arr + i) = 12;
	//}
	// the number of bytes bound is depend on type, eg., we can also have this char
	*(int *)((char *)ptr + 8) = 10;  // 4 + 4 = 8, 1 * 8 = 8
	// first ptr type-case to char *, then 8 blocks jump of char* then changed back to int *
	int *array = new int[5];  // this will be alive till deleted or throughout program(in heap) dynamic creation
	int (*array1)[5] = nullptr;  // is this similar to above line, what's the lifetime of this?
	//int (*array2)[] = &(int[]){0, 0, 0, 0, 0};  // isn't working, is this anonymous thing >c99 specifically ?
	delete[] array;
	delete[] array1;


	Entity e;  // at the address of e, we see, arr initialized with all 12 values
	Entity1 e1;  // at this address, we get another address, on that another address we'll get arr(indirection)

	// there's standard array now from c++11
	std::array<int, 5> newArray;  // this basically keeps tracks of size, bounds check and other stuff itself
	std::cout << newArray.size() << std::endl;

	/** trying something */
	const unsigned int size = 4;
	int *arr1 = new int[size];
	std::cout << "&arr1: " << &arr1 << std::endl;
	std::cout << "arr1: " << arr1 << std::endl;
	std::cout << "*arr1: " << *arr1 << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << "Entry at arr1 + "  << i << " " << arr1 + i << ": ";
		std::cin >> *(arr1 + i);
	}
	std::cout << "printing:" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << *(arr1 + i) << std::endl;
	}
	return 0;
}
