#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	vector<int> smallestK(vector<int>& arr, int k) {
		priority_queue<int> max_heap;
		for (auto item: arr) {
			if (max_heap.size() < k) {
				max_heap.push(item);
			} else if (!max_heap.empty() && max_heap.top() > item) {
				max_heap.pop();
				max_heap.push(item);
			}
		}
		vector<int> result;
		while (!max_heap.empty()) {
			result.push_back(max_heap.top());
			max_heap.pop();
		}
		return result;
	}
};

int main() {
	int k;
	cin >> k;
	int x;
	vector<int> arr;
	while (cin >> x) {
		arr.push_back(x);
	}

	Solution* solution = new Solution();
	vector<int> result = solution->smallestK(arr, k);
	for (auto item: result) 
		cout << item << " ";
	cout << endl;
	system("pause");
	return 0;
}