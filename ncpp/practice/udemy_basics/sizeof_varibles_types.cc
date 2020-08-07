// using sizeof operator

#include <iostream>
#include <climits>
#include <cfloat>

/* similar information for floating points number
 * can be found in <cfloat>
 * visit: http://www.cplusplus.com/reference/climits/ &
 * http://www.cplusplus.com/reference/cfloat/ for more details
 */

using std::cout;
using std::endl;

int main() {
	cout << "sizeof information" << endl;
	cout << "=====================" << endl;
	cout << "\n" << endl;
	cout << "climts" << endl;
	cout << "=====================" << endl;
	cout << "char: " << sizeof(char) << endl;
	cout << "unsigned short: " << sizeof(unsigned short) << endl;
	cout << "unsigned: " << sizeof(unsigned) << endl;
	cout << "unsigned long: " << sizeof(unsigned long) << endl;
	cout << "unsigned long long: " << sizeof(unsigned long long) << endl;
	cout << "int: " << sizeof(int) << endl;
	cout << "short: " << sizeof(short) << endl;
	cout << "long: " << sizeof(long) << endl;
	cout << "long long: " << sizeof(long long) << endl;

	cout << "=====================" << endl;
	cout << "float: " << sizeof(float) << endl;
	cout << "double: " << sizeof(double) << endl;
	cout << "long double: " << sizeof(long double) << endl;

	cout << "\n" << endl;

	cout << "Minimun Values" << endl;
	cout << "=====================" << endl;
	cout << "CHAR_MIN: " << CHAR_MIN << endl;
	cout << "SCHAR_MIN: " << SCHAR_MIN << endl;
	cout << "SHRT_MIN: " << SHRT_MIN << endl;
	cout << "INT_MIN: " << INT_MIN << endl;
	cout << "LONG_MIN: " << LONG_MIN << endl;
	cout << "LLONG_MIN: " << LLONG_MIN << endl;

	cout << "Maximum Values" << endl;
	cout << "=====================" << endl;
	cout << "CHAR_MAX: " << CHAR_MAX << endl;
	cout << "SCHAR_MAX: " << SCHAR_MAX << endl;
	cout << "SHRT_MAX: " << SHRT_MAX << endl;
	cout << "INT_MAX: " << INT_MAX << endl;
	cout << "LONG_MAX: " << LONG_MAX << endl;
	cout << "ULONG_MAX: " << ULONG_MAX << endl;
	cout << "LLONG_MAX: " << LLONG_MAX << endl;

	int radius_of_earth {6'371};
	// this tick is for reading convenience, compiler strips it out

	const double pi {3.14159265358979323846};
	// we are not using #define cause it isn't suggest to use it in modern C++

	unsigned long volume_of_earth {0};

	volume_of_earth = pi * radius_of_earth * radius_of_earth * radius_of_earth;

	cout << "\n" << endl;
	cout << "=====================" << endl;
	cout << "sizeof with variables" << endl;
	cout << "Size of (Radius_of_Earth): " << sizeof radius_of_earth << endl;
	cout << "Size of (pi): " << sizeof pi << endl;
	cout << "Size of (Volume of earth): " << pi * radius_of_earth * radius_of_earth * radius_of_earth << endl;
	cout << "Size of (Volume of earth): " << volume_of_earth << endl;
	cout << "Volume of Earth is: " << volume_of_earth << endl;

	cout << "\n" << endl;
	cout << "=====================" << endl;
	cout << "cfloat" << endl;

	cout << "Minimun Values" << endl;
	cout << "=====================" << endl;
	cout << FLT_MIN_EXP << endl;
	cout << DBL_MIN_EXP << endl;
	cout << LDBL_MIN_EXP << endl;
	cout << FLT_MIN_10_EXP << endl;
	cout << DBL_MIN_10_EXP << endl;
	cout << LDBL_MIN_10_EXP << endl;

	cout << "Maximum Values" << endl;
	cout << "=====================" << endl;
	cout << FLT_MAX_EXP << endl;
	cout << DBL_MAX_EXP << endl;
	cout << LDBL_MAX_EXP << endl;
	cout << FLT_MAX_10_EXP << endl;
	cout << DBL_MAX_10_EXP << endl;
	cout << LDBL_MAX_10_EXP << endl;

	cout << "Some other Values" << endl;
	cout << "=====================" << endl;
	cout << FLT_RADIX << endl;
	cout << FLT_MANT_DIG << endl;
	cout << FLT_DIG << endl;
	cout << FLT_EPSILON << endl;
	cout << FLT_ROUNDS << endl;
	cout << FLT_EVAL_METHOD << endl;
	cout << DECIMAL_DIG << endl;

	return 0;
}
