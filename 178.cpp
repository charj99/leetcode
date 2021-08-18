#include <iostream>
#include <cstring>
using namespace std;
#define MOD 1000000007
class Solution {
public:
	int checkRecord(int n) {
		int dp[n + 1][2][3];
		// dp[i][j][k], i days, j As, k conitnuous Ls
		memset(dp, 0, sizeof(dp));
		dp[1][0][0] = dp[1][0][1] = dp[1][1][0] = 1;
		for (int i = 2; i <= n; i++) {
			// ...P, ...LP, ...LLP
			dp[i][0][0] = add3(dp[i - 1][0][0], dp[i - 1][0][1], dp[i - 1][0][2]);
			// ...L
			dp[i][0][1] = dp[i - 1][0][0];
			// ...LL
			dp[i][0][2] = dp[i - 1][0][1];

			// ...A, ...LA, ...LLA, ..A..P, ..A..LP, ..A..LLP
			dp[i][1][0] = (add3(dp[i - 1][0][0], dp[i - 1][0][1], dp[i - 1][0][2])
				+ add3(dp[i - 1][1][0], dp[i - 1][1][1], dp[i - 1][1][2])) % MOD;
			// ..A..L
			dp[i][1][1] = dp[i - 1][1][0];
			// ..A..LL
			dp[i][1][2] = dp[i - 1][1][1];
		}
		int result = 0;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 3; j++)
				result = (result + dp[n][i][j]) % MOD;
		return result;
	}
private: 
	int add3(int a, int b, int c) {
		return (((a + b) % MOD) + c) % MOD;
	}
};
int main() {
	int n;
	cin >> n;
	Solution* solution = new Solution();
	cout << solution->checkRecord(n) << endl;
	system("pause");
	return 0;
}