#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAXL 100 // [-100, 100] ---> [0, 200]
class Solution {
public:
	bool checkValidString(string s) {
		int n = s.length();
		vector<vector<bool>> dp(n + 1, vector<bool> (MAXL * 2 + 1, false)); 
		
		// init
		dp[0][MAXL] = true;
		
		for (int i = 1; i <= n; i++) {
			char ch = s[i - 1];
			if (ch == '(') {
				for (int j = MAXL; j < MAXL * 2 + 1; j++) {
					if (j + 1 < MAXL * 2 + 1)
						dp[i][j + 1] = dp[i][j + 1] | dp[i - 1][j];
				}
			} else if (ch == ')') {
				for (int j = MAXL; j < MAXL * 2 + 1; j++) {
					if (j - 1 >= 0)
						dp[i][j - 1] = dp[i][j - 1] | dp[i - 1][j];
				}
			} else {
				for (int j = MAXL; j < MAXL * 2 + 1; j++) {
					if (j + 1 < MAXL * 2 + 1)
						dp[i][j + 1] = dp[i][j + 1] | dp[i - 1][j];
					if (j - 1 >= 0)
						dp[i][j - 1] = dp[i][j - 1] | dp[i - 1][j];
					dp[i][j] = dp[i][j] | dp[i - 1][j];
				}

			}
		}
		return dp[n][MAXL];
	}
};

int main() {
	string s;
	cin >> s;

	Solution* solution = new Solution();
	cout << (solution->checkValidString(s) ? "True" : "False") << endl;
	system("pause");
	return 0;
}