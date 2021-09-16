#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		if (!r) return 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (mid > 0 && mid < nums.size() - 1
			&& nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]
		    	|| mid == 0 && nums[mid] > nums[mid + 1] 
			|| mid == nums.size() - 1 && nums[mid] > nums[mid - 1])
				return mid;
			if (mid > 0 && nums[mid - 1] > nums[mid] 
			|| mid < nums.size() - 1 && nums[mid + 1] < nums[mid])
				r = mid - 1;
			else if (mid > 0 && nums[mid - 1] < nums[mid] 
			|| mid < nums.size() - 1 && nums[mid + 1] > nums[mid])
				l = mid + 1;
		}
		return -1;
	}
};

int main() {
	int x;
	vector<int> nums;
	while (cin >> x) {
		nums.push_back(x);
	}

	Solution* solution = new Solution();
	cout << solution->findPeakElement(nums) << endl;

	system("pause");
	return 0;
}