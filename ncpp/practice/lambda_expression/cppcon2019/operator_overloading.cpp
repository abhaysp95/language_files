#include <iostream>

class Plus {
	private:
		int _v;  // necessary
	public:
		Plus(int v): _v(v) {}
		int operator()(int x) const { return _v + x; }  // necessary(paramenter and return)
};

int main(int argc, char **argv) {
	Plus plus = Plus(10);  // necessary(value to constructor)
	int val1 = plus(32);
	std::cout << val1 << std::endl;
	// lambda implementation(things which are commented as necessary are only included)
	auto val2 = [_v = 1](int num){ return _v + num; };
	return 0;
}
