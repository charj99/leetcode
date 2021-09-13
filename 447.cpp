#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define DEBUG
#define abs(x) ((x) < 0 ? -(x) : (x))
class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int result = 0;
		int n = points.size();
		map<int, int> distMap;
		map<int, int>::iterator iter;
		for (int i = 0; i < n; i++) {
			distMap.clear();
			for (int j = 0; j < n; j++) {
				int d = dist(points[i], points[j]);
				iter = distMap.find(d);
				if (iter != distMap.end()) {
					iter->second += 1;
				} else distMap[d] = 1;
			}
			for (iter = distMap.begin(); iter != distMap.end(); iter++) {
				int num = iter->second;
				result += num * (num - 1);
			}
		}
		return result;
	}	
private: 
	int dist(vector<int>& x, vector<int>& y) {
		return (x[0] - y[0]) * (x[0] - y[0]) 
		+ (x[1] - y[1]) * (x[1] - y[1]);
	}
};

int main() {
	vector<int> point(2);
	vector<vector<int>> points;
	while (cin >> point[0] >> point[1]) {
		points.push_back(point);
	}
	
	Solution* solution = new Solution();
	cout << solution->numberOfBoomerangs(points) << endl;
	system("pause");
	return 0;
}