#include"Header.h"
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	unordered_set<int>s;
	int n = nums.size();
	if (k <= 0)return false;
	if (k >= n)k = n - 1;
	for (int i = 0; i < n; ++i)
	{
		if (i>k)s.erase(nums[i - k - 1]);
		if (s.find(nums[i]) != s.end())return true;
		s.insert(nums[i]);
	}
	return false;
	
}