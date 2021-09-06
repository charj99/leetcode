#include <iostream>
using namespace std;
#define MOD 1000000007
class Solution {
public:
	int fib(int n) {
		int fn = 1;
		int fn_1 = 0;
		if (n <= 1) return 0;
		for (int i = 2;  i <= n; i++) {
			int tmp = (fn + fn_1) % MOD;
			fn_1 = fn;
			fn = tmp;
		}	
		return fn;	
	}
};

int main() {
	int n;
	cin >> n;

	Solution* solution = new Solution();
	cout << solution->fib(n) << endl;
	system("pause");
	return 0;
}