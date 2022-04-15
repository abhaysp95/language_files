#include <iostream>

double
multiply(int x, int y)
{
	double res = 1;
	for (int i = 0; i < y; i++)
		res *= x;

	return res;
}

// n is nth root, and m is number
// e.g., n = 3, 27 => 3
void
getNthRoot(int n, int m)
{
	double low = 1;
	double high = m;
	double eps = 1e-6;

	while (high - low > eps) {
		double mid = (low + high) / 2.0;
		if (multiply(mid, n) >= m)
			high = mid;
		else
			low = mid;
	}

	printf("low: %f, high: %f\n", low, high);
}
/** Time complexity:
 * N * ln(m*(pow(10, d)))
 * N = number of iteration multiply is running for
 * m = number to find nth root of
 * d = number of decimal place
 */

int
main(int argc, char **argv)
{
	printf("getNthRoot(3, 27): \n");
	getNthRoot(3, 27);
}
