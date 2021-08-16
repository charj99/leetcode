#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
	    sort(arr.begin(), arr.end());
        if (arr[0] != 1) arr[0] = 1;
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] > 1) 
                arr[i] = arr[i - 1] + 1;
        }
        return arr[n - 1];
    }

};
main () {
	vi arr = {1, 2, 3, 4, 5};
	Solution* solution = new Solution();
	cout << solution->maximumElementAfterDecrementingAndRearranging(arr) << endl;
	return 0;
}