// main file

#include <iostream>

template <class temp>
class demo {
	public:
		temp square(temp x, temp y) {
			return x * y;
		}
};

int main(int argc, char **argv) {
	demo<int> sq;
	std::cout << sq.square(10, 20);
	return 0;
}