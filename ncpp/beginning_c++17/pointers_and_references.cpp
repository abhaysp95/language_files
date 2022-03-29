#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <memory>

void the_difference_between_pointers() {
	std::cout << "------" << __PRETTY_FUNCTION__ << "------\n";
	long numbers[] {10, 20, 30, 40, 50, 60, 70, 80, 90};
	long *pnum1{&numbers[6]};  // 7th element
	long *pnum2{&numbers[1]};  // 2nd element
	auto difference {pnum1 - pnum2};
	// what would be the type of auto, well, you can guss it as signed int, but
	// C++ (eventually can be used in C too) provide a platform specific type for this
	std::ptrdiff_t difference2 {pnum2 - pnum1};  // ptrdiff_t from stddef.h
	// going to write C style printing just to show the format specifier for std::ptrdiff_t
	printf("difference1: %ti, difference2: %td\n", difference, difference2);
	std::cout << "-------------------------------------------" << std::endl;
}

void dynamic_allocation_of_arrays() {
	std::cout << "------" << __PRETTY_FUNCTION__ << "------\n";
	// NOTE: you can't have dynamic array without specifying dimension, so this won't work
	// int *arr {new int[] {1, 2, 3}};
	// but this will work
	// int *arr {new int[3] {1, 2, 3}};

	// calculate prime
	size_t max{20};

	/* std::cout << "How many primes you like ? ";
	std::cin >> max; */

	if (max != 0) {
		auto* primes {new unsigned[max] {}};
		size_t count{1};
		*primes = 2;
		unsigned trial{3};
		while (count < max) {
			bool is_prime {true};

			const auto limit = static_cast<unsigned>(std::sqrt(trial));
			for (size_t i {}; *(primes + i) <= limit && is_prime; ++i) {
				is_prime = trial % *(primes + i) > 0;  // false for exact division
			}

			if (is_prime)
				*(primes + count++) = trial;
			trial += 2;
		}

		// output primes 10 to a lin
		for (size_t i {}; i < max; ++i)
		{
			std::cout << std::setw(7) << *(primes + i);
			if ((i + 1) % 10 == 0)
				std::cout << '\n';
		}
		std::cout << '\n';
		delete[] primes;
		primes = nullptr;
	}
	std::cout << "-------------------------------------------" << std::endl;
}

void multidimensional_arrays() {
	size_t rows {5}, columns {4};
	// auto carrots {new double[rows][columns] {}};  // won't work, also there's no delete[][]

	// however, say if you want to have columns of 4
	double (*carrots)[4] {new double[rows][4] {}};  // this means that size of array is 4 and is pointer to (arrary of) double
	// you can use auto instead of the above difficult type
	delete[] carrots;

	// to fully dynamic make a two-dimensional array
	double** arr {new double*[rows] {}};
	for (size_t i {}; i < rows; ++i)
		*(arr + i) = new double[columns] {};
	// to delete
	for (size_t i {}; i < rows; ++i)
		delete[] *(arr + i);
	delete[] arr, arr = nullptr;
}

void unique_ptr() {
	/**
	  * std::unique_ptr<> is used to make owning pointer, that means that it is
	  * unique and can't be copied
	  */

	// old way
	// std::unique_ptr<double> pdata {new double(999.0)};
	// new way (C++14 and onwards)
	std::unique_ptr<double> pdata = std::make_unique<double>(999.0);
	// the arguments to std::make_unique will be of what new T{...}
	std::unique_ptr<double>::pointer addr_pdata = pdata.get();  // returns const pointer address
	std::cout << "Address contained by smart pointer pdata: " << addr_pdata << '\n';

	// unique_ptr having array
	std::unique_ptr<double[]> parray = std::make_unique<double[]>({});  // empty array, you can put size instead of {} too
	pdata.reset(new double{100.0});  // no argument will reset pdata to nullptr (after free operation, ofcourse)
	double* pdumb_ptr = pdata.release();  // returns raw pointer
	delete pdumb_ptr, pdumb_ptr = nullptr;  // it is responsibility now to free and make sure there's no dangaling pointer
}

int main() {
	the_difference_between_pointers();
	dynamic_allocation_of_arrays();
	multidimensional_arrays();
	exit(0);
}
