#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int balancedStringSplit(string s) {
		int l = 0;
		int r = 0;
		int result = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'L') l++;
			if (s[i] == 'R') r++;
			if (l == r) result += 1;
		}
		return result;
	}
};

int main() {
	string s;
	cin >> s;

	Solution* solution = new Solution();
	cout << solution->balancedStringSplit(s) << endl;

	system("pause");
	return 0;
}