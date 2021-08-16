// 本代码二分 h 引用数，好像比较麻烦
// 可以考虑二分论文数
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int N = citations.size();
		if (citations[N - 1] == 0) return 0; // important, for case [0, ..., 0]
		int l = 0, r = citations.size() - 1;
		while (l < r - 1) {
			int mid = (l + r) / 2;
			if (citations[mid] > N - mid)
				r = mid;
			else l = mid;
		}
		// l does not satisfy
		if (citations[l] > N) return N;
		
		// l satisfy, judge wether there is larger h
		if (l + 1 < N && citations[l] < N - l && citations[l + 1] >= N - l - 1) return N - l - 1;
		else return N - l;
  	}
};

int main() {
	Solution* solution = new Solution();
	vi citations = {0, 1, 3, 5, 6};
	solution->hIndex(citations);
	return 0;
}