#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
	int findMaximizedCapital(
		int k, int w, vector<int>& profits, vector<int>& capital) {
		
		int n = profits.size();
		vector<pair<int, int>> cp_pair_list;
		for (int i = 0; i < n; i++) {
			cp_pair_list.push_back(make_pair(capital[i], profits[i]));	
		}
		sort(cp_pair_list.begin(), cp_pair_list.end());

		priority_queue<int> max_heap;
		int j = 0;
		int result = w;
		for (int i = 0; i < min(k, n); i++) {
			while (j < n && cp_pair_list[j].first <= result) {
				max_heap.push(cp_pair_list[j].second);
				j++; 
			}

			if (!max_heap.empty()) {
				result += max_heap.top();
				max_heap.pop();
			}
		}
		return result;
	}
};

int main() {
	int k, w;
	cin >> k >> w;
	int p, c;
	vector<int> profits;
	vector<int> capital;
	while (cin >> p >> c) {
		profits.push_back(p);
		capital.push_back(c);
	}
	Solution* soluiton = new Solution();
	cout << soluiton->findMaximizedCapital(k, w, profits, capital) << endl;
	system("pause");
	return 0;
}