// main file

#include <iostream>

class Pair {
	public:
		double a, b;
		Pair(double x, double y) {
			a = x;
			b = y;
		}
};

class equalPair: public Pair {
	public:
		bool equal;
		equalPair(): equalPair(0.0, 0.0) {}
		equalPair(double a, double b): Pair(a, b) {
			equal = (a == b);
		}
};

int main(int argc, char **argv) {
	equalPair first(10.0, 10.000);
	equalPair second;
	std::cout << first.equal << std::endl;
	std::cout << second.equal << std::endl;
    return 0;
}