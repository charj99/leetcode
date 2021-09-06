#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// #define DEBUG
class Solution {
public:
	int numRescueBoats(vector<int>& people, int limit) {
		int result = 0;
		sort(people.begin(), people.end());
#ifdef DEBUG
		for (auto weight: people) 
			cout << weight << " ";
		cout << endl;
#endif
		int j = 0;
		for (int i = people.size() - 1; i >= j; i--) {
			if (i != j && people[i] + people[j] <= limit) {
				result++;
				j++;
			} else result++;
		}
		return result;	
	}
};

int main() {
	int limit;
	cin >> limit;
	int weight;
	vector<int> people;
	while (cin >> weight)
		people.push_back(weight);

	Solution* solution = new Solution();
	cout << solution->numRescueBoats(people, limit) << endl;
	system("pause");
	return 0;
}