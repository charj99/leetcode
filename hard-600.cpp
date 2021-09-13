/*
0
1	dp[1] = 2

10	dp[2] = 3

100	
101	dp[3] = 3 + 2 = 5

1000
1001
1010   dp[4] = 5 + 3 = 8

10000
10001
10010
10100
10101

11011
[0, 1111]
[10000, 11011] ---> 1[0, 1011]
1011
[0, 111]
[1000, 1011] ---> 1[0, 011]
11

1010
[0, 111] = 5
[1000, 1010] ---> 1[0, 010]
10

*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
	int findIntegers(int n) {
		vector<int> dp(32, 0);
		dp[0] = 1;
		dp[1] = 2;
		int i;
		for (i = 2; (1 << i) - 1 <= n; i++) {
			dp[i] += dp[i - 1] + dp[i - 2]; 
		}
		int result = 0;
		int last = -1;
		while (i >= 0) {
			if (n & (1 << i)) {
				if (last == -1 ||
				last != -1 && last > i + 1)
					result += dp[i];
				else {
					result += dp[i];
					return result;
				}
				last = i;
			}
			i--;
		}
		return result + 1;
	}
};

int main() {
	int n;
	cin >> n;
	Solution* solution = new Solution();
	cout << solution->findIntegers(n) << endl;
	system("pause");
	return 0;
}