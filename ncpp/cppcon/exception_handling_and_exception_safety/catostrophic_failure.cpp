#include <iostream>
#include <exception>
#include <array>

class temp {
	private:
		std::array<int, 5>* _tarr;
	public:
		temp() {
			std::cout << "temp constructor called\n";
			this->_tarr = new std::array<int, 5>;
		}
		~temp() {
			std::cout << "temp destructor called\n";
			if (this->_tarr) {
				delete this->_tarr;
				this->_tarr = nullptr;
			}
		}
};

class catostrophic_failure: public std::exception {
	private:
		std::array<int, 10>* _arr;
	public:
		catostrophic_failure() {
			this->_arr = new std::array<int, 10>;
		}
		~catostrophic_failure() {
			if (this->_arr)
				delete this->_arr;
		}
};

void g() {
	std::cout << "Enter 0 or 1\n";
	int in{};
	std::cin >> in;
	std::array<int, 10>* arr = new std::array<int, 10>;
	temp tp;
	try {
		if (!in)
			throw catostrophic_failure();
	}
	catch (std::exception& e) {
		delete arr;
		arr = nullptr;
		throw;
	}
	std::cout << "Out of g()\n";
}

void f() noexcept {
	try {
		g();
	}
	catch(std::out_of_range& e) {
		e.what();
	}
	std::cout << "Out of f()\n";
}

int main(int argc, char** argv) {
	try {
		f();
	}
	catch (std::overflow_error& e) {
		e.what();
	}
	std::cout << "Out of main()\n";
}
