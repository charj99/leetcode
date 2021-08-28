#include <iostream>
#include <vector>
using namespace std;
int myAbs(int x) {
	return x >= 0 ? x : -x;
}
class Solution {
public:
	bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
		int targetStep = myAbs(target[0]) + myAbs(target[1]);
		for (int i = 0; i < ghosts.size(); i++) {
			int step = myAbs(ghosts[i][0] - target[0]) + myAbs(ghosts[i][1] - target[1]);
			if (step <= targetStep) return false;	
		
		}
		return true;
	}
};

int main() {
	vector<int> target(2);
	cin >> target[0] >> target[1];

	int n;
	cin >> n;
	vector<vector<int>> ghosts(n, vector<int>(2));
	for (int i = 0; i < n; i++)
		cin >> ghosts[i][0] >> ghosts[i][1];
	
	Solution* solution = new Solution();
	cout << (solution->escapeGhosts(ghosts, target) ? "true" : "false") << endl;
	system("pause");
	return 0;
}