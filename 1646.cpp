#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG
class Solution {
public:
	int getMaximumGenerated(int n) {
		if (!n) return 0;
		vector<int> nums(n + 1);
		nums[0] = 0;
		nums[1] = 1;
		for (int i = 1; 2 * i <= n; i++) {
			nums[2 * i] = nums[i];
			if (2 * i + 1 <= n)
				nums[2 * i + 1] = nums[i] + nums[i + 1];
		}

		int result = 0;
		for (int i = 0; i <= n; i++) {
			result = max(result, nums[i]);
#ifdef DEBUG
			cout << i << ": " << nums[i] << endl;
#endif
		}
		return result;
	}
};

int main() {
	int n;
	cin >> n;
	Solution* solution = new Solution();
	cout << solution->getMaximumGenerated(n) << endl;
	system("pause");
	return 0;
}