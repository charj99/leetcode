#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int chalkReplacer(vector<int>& chalk, int k) {
		int n = chalk.size();
		vector<long long> pre;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += chalk[i];
			pre.push_back(sum);
		}
		int remain = k % sum;
		if (!remain) return 0;
		int i = 0;
		while (i < n && pre[i] <= remain) {
			i++;
		}
		return i;
	}
};

int main() {
	int k;
	cin >> k;
	int num;
	vector<int> chalk;
	while (cin >> num) chalk.push_back(num);

	Solution* solution = new Solution();
	cout << solution->chalkReplacer(chalk, k) << endl;
	system("pause");
	return 0;
}