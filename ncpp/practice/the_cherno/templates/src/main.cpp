// main file

#include <iostream>
#include <string>

// template are created when we call the template function only
template<typename _Tp>
void print(_Tp value) {
	std::cout << value << std::endl;
}

// create array on stack with size provided later when called
template<typename _Tp, int _size>
class array {
	private:
		_Tp _arr[_size];
	public:
		size_t get_size() const { return _size; }
};

int main(int argc, char **argv) {
	print(5);
	print<std::string>("5");
	print("5");  // can automatically deduce type
	array<int, 5> arr;
	std::cout << arr.get_size() << std::endl;
	// write code for array in entry
	return 0;
}