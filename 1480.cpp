#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {
		int n = nums.size();
		vector<int> result(n);
		int sum = 0;
		for (int i = 0; i < n; i++)
			result[i] = (sum += nums[i]);
		return result; 
	}
};
int main() {
	vector<int> nums;
	int x;
	while (cin >> x) nums.push_back(x);
	
	Solution* solution = new Solution();
	vector<int> result = solution->runningSum(nums);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	system("pause");
	return 0;
}