#include <iostream>
#include <vector>
#include <optional>

using namespace std;

optional<size_t> check(const vector<int>& nums)
{
	for (int i {}; i < nums.size() - 1; i++)
	{
		if (i % 2 == 0)
		{
			if (nums[i] == nums[i + 1])
			{
				return i;
			}
		}
	}
	return nullopt;
}

int minDeletion(vector<int>& nums)
{

}
