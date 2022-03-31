#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// not correct
int maxValueOfCoins(vector<vector<int>>& piles, int k)
{
	int max {-numeric_limits<int>::infinity()};
	for (size_t i {}; i < piles.size(); i++)
	{
		int sum {};
		for (size_t j {}; j < piles[i].size() && j < k; j++)
		{
			sum += piles[i][j];
		}
		if (max < sum)
			max = sum;
	}
	return max;
}

int main(int argc, char** argv)
{
	vector<vector<int>> arr = {
		{100},
		{100},
		{100},
		{100},
		{100},
		{100},
		{1,1,1,1,1,1,700}
	};
	size_t k {7};
	std::cout << maxValueOfCoins(arr, k) << std::endl;
}
