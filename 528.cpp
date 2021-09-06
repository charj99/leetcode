#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
// #define DEBUG
class Solution {
public:
	Solution (vector<int> &w) {
		this->w = w;
		this->sum = 0;
		this->pre.push_back(0);
		for (int i = 0; i < w.size(); i++) {
			this->sum += w[i];
			this->pre.push_back(sum);
		}
#ifdef DEBUG
		for (int i = 0; i <= w.size(); i++)
			cout << this->pre[i] << " ";
#endif
		srand(time(0));
	}

	int pickIndex() {
		int x = rand() % sum;
		/*
		for (int i = 1; i <= this->w.size(); i++) {
			if (x >= this->pre[i - 1] && x < this->pre[i])
				return (i - 1);
		}
		*/
		int l = 0, r = this->w.size();
		while (l < r - 1) {
			int mid = (l + r) / 2;
			if (x < pre[mid]) r = mid;
			if (x >= pre[mid]) l = mid;
		}
		return l;
	}
private:
	vector<int> w;
	int sum;
	vector<int> pre;
};

int main() {
	int n;
	cin >> n;

	int x;
	vector<int> w;
	while (cin >> x)
		w.push_back(x);

	Solution* solution = new Solution(w);	
	for (int i = 0; i < n; i++)
		cout << solution->pickIndex() << " ";

	system("pause");
	return 0;
}