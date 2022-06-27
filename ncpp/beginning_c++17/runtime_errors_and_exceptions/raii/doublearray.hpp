#ifndef _DOUBLEARRAY_HPP
#define _DOUBLEARRAY_HPP


#include <cstddef>
#include <iostream>

class DoubleArray {
	private:
		double* resource;

	public:
		DoubleArray(size_t sz)
			:resource{ new double[sz] } {}
		~DoubleArray() {
			std::cout << "Freeing memory..." << std::endl;
			delete[] this->resource;
		}

		// delete copy constructor and copy assignment operator
		DoubleArray(const DoubleArray&) = delete;
		DoubleArray& operator=(const DoubleArray&) = delete;

		// array subscript operator
		double& operator[](const size_t index) noexcept {
			return this->resource[index];
		}
		const double& operator[](const size_t index) const noexcept {
			return this->resource[index];
		}

		// function to acess encapsulated resource
		double* get() const noexcept {
			return this->resource;
		}

		// hand over the resource, once called, destructor will no longer clear
		// up the resource
		double* release() noexcept {
			double* result = this->resource;
			this->resource = nullptr;
			return result;
		}
};

#endif
