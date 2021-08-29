#include <iostream>
#include <vector>
using namespace std;
#define INF 0x7fff0000
class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		int result = INF;
		vector<vector<int>> dp(k + 2, vector<int> (n, INF));
		dp[0][src] = 0;
		for (int i = 1; i <= k + 1; i++)
			for (int j = 0; j < flights.size(); j++) {
				int from = flights[j][0];
				int to = flights[j][1];
				int price = flights[j][2];
				dp[i][to] = min(dp[i][to], dp[i - 1][from] + price);
				if (to == dst)
					result = min(result, dp[i][to]);
			}
		return result == INF ? -1 : result;
	}
};

int main() {	
	int n;
	cin >> n;

	int src, dst, k;
	cin >> src >> dst >> k;
	int from, to, price;

	vector<vector<int>> flights;
	while (cin >> from >> to >> price) {
		vector<int> flight;
		flight.push_back(from);
		flight.push_back(to);
		flight.push_back(price);
		flights.push_back(flight);
	}

	Solution* solution = new Solution();
	cout << solution->findCheapestPrice(n, flights, src, dst, k) << endl;
	system("pause");
	return 0;
}