#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		int minDeletion(vector<int>& nums)
		{
			int del {};
			size_t sz = nums.size();
			for (size_t i {}; i < sz; i++)
			{
				int delta = i - del;
				if (nums[i] == nums[i + 1] && delta % 2 == 0)
					del++;
			}
			if ((sz - del) % 2 != 0)
				del++;
			return del;
		}
};

int main(int argc, char** argv)
{
	vector<int> vec {1, 1, 2, 2, 3, 3};
	Solution sol {};
	std::cout << sol.minDeletion(vec) << std::endl;
}
