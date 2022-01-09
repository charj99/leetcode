#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		int n =  nums.size();
		if (n == 1) return 1;
		vector<pair<int, int>> dp(n, make_pair(0, 0));
		dp[0] = make_pair(1, 1);
		int LIS = 0;
		for (int i = 1; i < n; i++) {
			dp[i] = make_pair(1, 1);
			for (int j = 0; j < i; j++) {
				if (nums[i] <= nums[j]) continue;
				int maxL = dp[j].first;
				int num = dp[j].second;
				if (maxL + 1 > dp[i].first) 
					dp[i] = make_pair(maxL + 1, num);
				else if (maxL + 1 == dp[i].first) 
					dp[i] = make_pair(maxL + 1, dp[i].second + num);
			}
			LIS = max(LIS, dp[i].first);
		}
#ifdef DEBUG
		cout << LIS << endl; 
#endif

		int result = 0;
		for (int i = 0; i < n; i++)
			if (dp[i].first == LIS)
				result += dp[i].second;
		return result;

	}
};
int main() {
	int x;
	vector<int> nums;
	while (cin >> x) nums.push_back(x);

	Solution* solution = new Solution();
	cout << solution->findNumberOfLIS(nums) << endl;

	system("pause");
	return 0;
}