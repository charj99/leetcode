#include <iostream>
using namespace std;
class Solution {
public:
	int minSteps(int n) {
		if (n == 1) return 0;
		int result = 0;
		int val = n;
		for (int i = 2; i <= val; i++) {
			while (val % i == 0) {
				result += i;
				val /= i;
			}
		}
		return result;
	}
};

int main() {
	int n;
	cin >> n;

	Solution* solution = new Solution();
	cout << solution->minSteps(n) << endl;

	system("pause");
	return 0;
}