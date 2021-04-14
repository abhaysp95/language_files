// main file

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

/* ramanujan formula for finding factorial:
   sqrt(pi) * pow(n / exp(1), n) * pow((8 * pow(n, 3)) + (4 * pow(n, 2)) + n + (1 / pow(pi, 3)), (1 / 6))
   */

/* unsigned long long
factorial(unsigned long long num)
{
	if (num <= 1) {
		return 1;
	}
	return num * factorial(num - 1);
} */

/* unsigned long
get_gcd(unsigned long long fa, unsigned long long fb)
{
	if (fa % fb == 0) {
		return fb;
	}
	unsigned long long min_val = min(fa, fb);
	return get_gcd(min_val, fa % fb);
} */

void print_vec(const list<int>& num) {
	for (const int& n: num) {
		cout << n;
	}
	cout << endl;
}

void
multiply(const unsigned long long& multiplier, list<int>& multiplicand)
{
	unsigned long carry{};  // carry = 0
	// starts from reverse
	for (list<int>::reverse_iterator iter = multiplicand.rbegin(); iter != multiplicand.rend(); ++iter) {
		unsigned long long product = (*iter * multiplier) + carry;
		*iter = product % 10;
		carry = product / 10;
	}
	// for this reason(push_front), I chose list
	while (carry > 0) {
		multiplicand.push_front(carry % 10);
		carry /= 10;
	}
}

list<int>
factorial(unsigned long long num)
{
	list<int> res{1};
	for (unsigned long long idx = 2; idx <= num; ++idx) {
		// multiply idx * res
		multiply(idx, res);
	}
	return res;
}

/* list<int>
get_gcd(list<int>& a, list<int>& b)
{
	list<int> gcd{1};
	list<int> temp_count{1};
	while (divide(temp_count, a) != 0 && divide(temp_count, b) != 0) {

	}
} */

int main(int argc, char **argv) {
	unsigned long long a{}, b{};
	cin >> a >> b;
	//list<int> afact = factorial(a);
	//list<int> bfact = factorial(b);
	//print_vec(afact);
	//print_vec(bfact);
	/*unsigned long long fa{}, fb{};
	fa = factorial(a);
	fb = factorial(b);
	cout << "fa: " << fa << ", fb: " << fb << '\n';
	unsigned long got_gcd = get_gcd(fa, fb);
	cout << got_gcd << endl;*/

	/** GCD of the factorials will be the factorial of minimum number */
	unsigned long long answer{1};
	for (unsigned long long idx = 2; idx <= min(a, b); ++idx) {
		answer *= idx;
	}
	cout << answer << endl;
	return 0;
}