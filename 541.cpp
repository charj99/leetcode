#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.length(); i += 2 * k) {
			reverse(s, i, k);
		}
		return s;
	}
private:
	void reverse(string& s, int begin, int length) {
		int end = min(begin + length, (int)s.length()) - 1;
		for (int i = begin, j = end; i < j; i++, j--) 
			swap(s[i], s[j]); 
	}
};
int main() {
	string s;
	int k;
	cin >> s;
	cin >> k;
	Solution* solution = new Solution();
	cout << solution->reverseStr(s, k) << endl;
	system("pause");
	return 0;
}