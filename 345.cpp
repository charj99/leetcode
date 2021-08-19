#include <iostream>
using namespace std;
class Solution {
public:
	string reverseVowels(string s) {
		int i = 0, j = s.length() - 1;
		while (i < j) {
			while (i < j && !isVowels(s[i])) i++;
			while (j > i && !isVowels(s[j])) j--;
			swap(s[i], s[j]);
			i++;
			j--;
		}
		return s;
	}
private:
	bool isVowels(char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
		|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	}
};

int main() {
	string s;
	cin >> s;
	Solution* solution = new Solution();
	cout << solution->reverseVowels(s) << endl;
	system("pause");
	return 0;
}