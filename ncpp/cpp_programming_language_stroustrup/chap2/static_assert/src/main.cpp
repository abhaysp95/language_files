// main file

#include <iostream>

//constexpr int C = 299792.458;
constexpr int C = 299792;

void f(double speed) {
	const double local_max1 = 160.0 / (60 * 60);
	const int local_max = 160 / (60 * 60);
	// static_assert(speed < c, "can't go that fast");
	static_assert(local_max < C, "can't go that fast");
}

int main(int argc, char **argv) {
	/* code here */
	return 0;
}