#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define DEBUG
class Solution {
private:
	string bigIntAdd(const string& a, const string& b) {
		int n1 = a.length();
		int n2 = b.length();
		int i = n1 - 1, j = n2 - 1;
		int csum = 0;
		string sum;
		while (i >= 0 && j >= 0) {
			int c = a[i] - '0' + b[j] - '0' + csum;
			sum += c % 10 + '0';
			csum = c / 10; 	
			i--;
		 	j--;
		}
		while (i >= 0) {
			int c = a[i] - '0' + csum;
			sum += c % 10 + '0';
			csum = c / 10; 	
			i--;
		} 
		while (j >= 0) {
			int c = b[j] - '0' + csum;
			sum += c % 10 + '0';
			csum = c / 10; 	
			j--;
		}
		if (csum) sum += csum + '0';
		reverse(sum.begin(), sum.end());
		return sum;
	}

	bool predZero(const string& s) {
		if (s.length() == 1 && s[0] == '0') return false;
		return s[0] == '0';
	}

	// [0, i), [i, j) [j, n)
	bool judge(const string& num, int end1, int end2) {
		string a = num.substr(0, end1);
		string b = num.substr(end1, end2 - end1);
		if (predZero(a) || predZero(b)) return false;
		string sum = bigIntAdd(a, b);
#ifdef DEBUG
		cout << a + " + " + b + " = " + sum << endl;
#endif
		while (end2 < num.length()) {
			if (num.substr(end2, sum.length()) != sum) 
				return false;
			end1 += b.length(); 
			end2 += sum.length();
			a = b;
			b = sum;
			if (predZero(a) || predZero(b)) return false;
			sum = bigIntAdd(a, b);
#ifdef DEBUG
			cout << a + " + " + b + " = " + sum << endl;
#endif
		}
		return true;
	}
public:
	bool isAdditiveNumber(string num) {
		int n = num.length();
		// [0, i), [i, j)
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (judge(num, i, j))
					return true;
		return false;
	}
};
int main() {
	string num;
	cin >> num;
	Solution* solution = new Solution();
	cout << (solution->isAdditiveNumber(num) ? "true" : "false") << endl;
	system("pause");
	return 0;
}