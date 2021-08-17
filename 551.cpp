#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool checkRecord(string s) {
		int cntL = 0;
		int cntA = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'A') {
				cntA++;
				cntL = 0;
			}
			else if (s[i] == 'L') {
				cntL++;
			} else {
				cntL = 0;
			}
			if (cntA >= 2 || cntL >= 3) return false; 
		}
		return true;
	}
};

int main() {
	string s;
	cin >> s;
	Solution* solution = new Solution();
	cout << (solution->checkRecord(s) ? "true" : "false") << endl;
	system("pause");
	return 0;
}