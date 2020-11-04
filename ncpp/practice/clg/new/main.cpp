#include <iostream>

int main(int argc, char **argv) {
	int *p = new int;
	*p = 2;
	std::cout << *p << std::endl;
	std::cout << "--------------" << std::endl;

	const size_t size = 3;
	int *p1 = new int[size];
	for (int i = 0; i < size; ++i) {
		*(p1 + i) = i + 1;
		std::cout << *(p1 + 1) << std::endl;
	}
	std::cout << "--------------" << std::endl;

	int **p2 = new int*[size];
	for (int i = 0; i < size; ++i) {
		//p[i] = new int[size];
		*(p2 + i) = new int[size];
	}
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			//std::cin >> p2[i][j];
			//p2[i][j] = i + j + 1;
			*(*(p2 + i) + j) = i + j + 1;
		}
	}
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << *(*(p2 + i) + j) << std::endl;
		}
	}

	// delete
	delete p;
	delete[] p1;

	/* p2 is also an array which just instead of numbers holds the address for
	 * another array of numbers, so first delete those internal arrays and then
	 * delete p2 */
	for (int i = 0; i < size; ++i) {
		// delete *(p2 + i);
		// or use delete[] p2[i];
		delete[] (p2 + i);
	}
	delete[] p2;

	std::cout << "*** After deletion *p2 ***" << std::endl;

	for (int i = 1; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << *(*(p2 + i) + j) << std::endl;
		}
	}

	p = nullptr;
	p1 = nullptr;
	p2 = nullptr;
	return 0;
}
