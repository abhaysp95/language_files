#include <complex.h>

int main(int argc, char **argv) {
	short n = -10;
	double x = 0.5, y = 0.0;
	float _Complex f_z = 2.0F + 3.0F * I;
	double _Complex d_z = 0.0;
	y = n * x;  // value of n is converted to type double
	d_z = f_z + x;  // only value of f_z is converted to double _Complex, result will also have typed double _Complex
	f_z = f_z / 3;  // The constant 3 is converted to float
	d_z = d_z - f_z;  // value of f_z is converted to type double _Complex
	return 0;
}
