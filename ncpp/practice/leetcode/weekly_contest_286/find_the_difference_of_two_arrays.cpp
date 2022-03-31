#include <iostream>
#include <vector>


using namespace std;

vector<int> difference(const vector<int>& num1, const vector<int>& num2)
{
	if (num1.empty()) return vector<int> {};
	vector<int> diff {};
	for (const auto x: num1)
	{
		bool not_found {true};
		for (const auto y: num2) {
			if (x == y)
			{
				not_found = false;
				break;
			}
		}

		if (not_found)
		{
			if (diff.empty())
				diff.push_back(x);
			else
			{
				bool nf {true};
				for (const auto y: diff)
				{
					if (x == y) {
						nf = false;
						break;
					}
				}
				if (nf)
					diff.push_back(x);
			}
		}
	}
	return diff;
}

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
{
	vector<vector<int>> ret (2);
	ret[0] = difference(nums1, nums2);
	ret[1] = difference(nums2, nums1);
	return ret;
}

int main(int argc, char** argv)
{
	vector<int> a{1, 2, 3, 3}, b{2, 4, 6};
	auto res {findDifference(a, b)};
	for (const auto& vec: res)
	{
		for (const auto x: vec)
			std::cout << x << ' ' << '\n';
		std::cout << '\n';
	}
}
