#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // reverse();
using namespace std;
#define DEBUG 1
class Solution {
public:
	int compress(vector<char>& chars) {
		int n = chars.size();
		int i = 0;
		int j = 0;
		int cnt = 1;
		chars[j++] = chars[i++];
		while (i < n) {
			if (chars[i] == chars[i - 1]) {
				while (i < n && chars[i] == chars[i - 1]) cnt++, i++;
				set_dec(chars, &j, cnt);
			}
			if (i >= n) break;
			chars[j++] = chars[i++];
			cnt = 1;
		}
		
		if (DEBUG) {
			for (int i = 0; i < j; i++)
				cout << chars[i];
			cout << endl;
		}
		
		return j;
	}
private:
	void set_dec(vector<char>& chars, int* j, int cnt) {
		int begin = *j;
		while (cnt) {
			chars[(*j)++] = (cnt % 10) + '0';
			cnt /= 10;
		}
		reverse(chars.begin() + begin, chars.begin() + (*j));

	}
};

int main() {
	string s;
	cin >> s;
	Solution* solution = new Solution();
	vector<char> chars;
	for (int i = 0; i < s.length(); i++)
		chars.push_back(s[i]);
	cout << solution->compress(chars) << endl;
	system("pause");
	return 0;
}