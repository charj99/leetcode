#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (nums[mid] == target) return mid;
			if (target > nums[mid]) l = mid + 1;
			else if (target < nums[mid]) r = mid - 1; 
		}
		return -1;
	}
};

int main() {
	int target;
	cin >> target;
	int x;
	vector<int> nums;
	while (cin >> x) {
		nums.push_back(x);
	}

	Solution* solution = new Solution();
	cout << solution->search(nums, target) << endl;
	system("pause");
	return 0;

}