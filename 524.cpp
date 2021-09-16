#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// #define DEBUG
static bool cmp(const string& a, const string& b);

class Solution {
public:
	string findLongestWord(string s, vector<string>& dictionary) {
		sort(dictionary.begin(), dictionary.end(), cmp);
#ifdef DEBUG
		for (auto word : dictionary) {
			cout << word << endl;
		}
#endif
		for (auto word : dictionary) {
			if (canMatch(s, word)) return word;
		}
		return "";
	}
private:
	bool canMatch(const string& s, const string& a) {
		int j = 0;
		for (int i = 0; i < a.length(); i++) {
			while (j < s.length() && s[j] != a[i]) j++;
			if (j >= s.length()) return false;
			else j++;
		}
		return true;
	}
};

static bool cmp(const string& a, const string& b) {
	if (a.length() == b.length())
		return a < b;
	return a.length() > b.length();
}
int main() {
	string s;
	cin >> s;
	string word;
	vector<string> dictionary;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> word;
		dictionary.push_back(word);
	}

	Solution* solution = new Solution();
	cout << solution->findLongestWord(s, dictionary) << endl;
	system("pause");
	return 0;
}