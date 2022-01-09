#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size();
		int m = word2.size();
		vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i][j - 1];
				int index = i;
				while (index && word1[index - 1] != word2[j - 1]) {
					index--;
				}
				if (index)
					dp[i][j] = max(dp[i][j], 
					dp[index - 1][j - 1] + 1);
			}
			return n + m - 2 * dp[n][m];
	}
};

int main() {
	string word1;
	string word2;
	cin >> word1 >> word2;
	
	Solution* solution = new Solution();
	cout << solution->minDistance(word1, word2) << endl;

	system("pause");
	return 0;
}
