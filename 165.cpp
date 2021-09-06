#include <iostream>
using namespace std;
class Solution {
public:
	int compareVersion(string version1, string version2) {
		int i = 0, j = 0;
		while (i < version1.length() || j < version2.length()) {
			int v1 = getVersion(version1, &i);
			int v2 = getVersion(version2, &j);
			if (v1 > v2) return 1;
			else if (v1 < v2) return -1; 
		}
		return 0;
	}
private:
	int getVersion(string& v, int* index_p) {
		int index = *index_p;
		int value = 0;
		while (index < v.length() && v[index] != '.') {
			value = value * 10 + (v[index] - '0');
			index++;
		}
		index++;
		*index_p = index; 
		return value;
	}
};

int main() {
	string version1;
	string version2;
	cin >> version1 >> version2;

	Solution* solution = new Solution();
	cout << solution->compareVersion(version1, version2) << endl;
	system("pause");
	return 0;
}