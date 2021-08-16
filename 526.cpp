#include <iostream>
#include <vector>
using namespace std;


typedef vector<bool> vi;

class Solution {
private:
	int dfs(int dep, int n, vi& visited);
public:
	int countArrangement(int n) {
		vi visited(n + 1, false);
		return dfs(1, n, visited);
	}
};

int Solution::dfs(int dep, int n, vi& visited) {
	if (dep > n) return 1;
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && (i % dep == 0 || dep % i == 0)) {
			visited[i] = true;
			result += dfs(dep + 1, n, visited);
			visited[i] = false;
		}
	
	}
	return result; 
}

int main() {
	int n;
	cin >> n;
	Solution* solution = new Solution();
	cout << solution->countArrangement(n) << endl;
	system("pause"); // 
	return 0;	
}