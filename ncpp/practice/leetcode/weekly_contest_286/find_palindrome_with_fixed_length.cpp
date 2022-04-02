#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
	public:
		vector<long long> kthPalindrome(vector<int>& queries, int length)
		{
			vector<long long> ret {};
			if (length < 2) return ret;

			int base = (length%2 == 0) ? pow(10, (length/2)-1) : pow(10, length/2);
			for (const auto& q: queries)
				ret.push_back(base + q - 1);

			makePalindrome(ret, length % 2 == 0);

			// check for valid answer
			for (auto& x: ret)
				if (int(log10(x)) != length)
					x = -1;

			return ret;
		}

	private:
		void makePalindrome(vector<long long>& vec, bool isEven)
		{
			for (auto& x: vec)
			{
				auto res = isEven ? palindrome(x) : palindrome(x / 10);
				// printf("%lld, %lld\n", x, res);
				auto pow {10};
				while (res >= pow)
					pow *= 10;
				x = x * pow + res;
			}
		}

		long long palindrome(long long temp) {
			auto res = 0;
			while (temp != 0)
			{
				auto rem = temp % 10;
				temp /= 10;
				res = (res * 10) + rem;
			}
			return res;
		}
};

int main(int argc, char** argv)
{
	vector<int> queries {2, 4, 6};
	int length {4};
	Solution sol {};
	auto res = sol.kthPalindrome(queries, length);
	for (const auto& x : res)
		std::cout << x << '\n';
	std::cout << std::endl;
}

/**
 * Input:
 * 1. {1, 2, 3, 4, 5, 90}, 3
 * 2. {2, 4, 6}, 4
 */

/**
 * you can use std::to_string(), strtoll(), sprintf() etc. if you want to use
 * string approach for palindrome
 */
