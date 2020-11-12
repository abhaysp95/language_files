// main file

#include <iostream>

class Pair {
	private:
		int a, b;
	public:
		Pair(int a, int b) {
			this->a = a;
			this->b = b;
		}
};

class sumPair: public Pair {
	public:
		int sum;
		sumPair(int a, int b): Pair(a, b) {
			sum = a + b;
		}
};

int main(int argc, char **argv) {
	sumPair sp(15, 16);
	std::cout << sp.sum << std::endl;
    return 0;
}