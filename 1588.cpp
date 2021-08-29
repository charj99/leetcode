#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int sumOddLengthSubarrays(vector<int> &arr) {
		int result = 0;
		for (int length = 1; length <= arr.size(); length += 2) {
			int sum = 0;
			for (int i = 0; i < length; i++) {
				sum += arr[i];
			}
			result += sum;
			for (int i = 0; i + length < arr.size(); i++) {
				sum = sum - arr[i] + arr[i + length];
				result += sum;
			}
		}
		return result;
	}
};

int main() {
	int x;
	vector<int> arr;
	while (cin >> x) {
		arr.push_back(x);
	}

	Solution* solution = new Solution();
	cout << solution->sumOddLengthSubarrays(arr) << endl;
	system("pause");
	return 0;
}