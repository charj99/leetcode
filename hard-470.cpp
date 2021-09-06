#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
class Solution {
public:

	int rand10() {
		int index;
		do {
			int x = rand7();
			int y = rand7();
			index = (x - 1) * 7 + y;
		} while (index > 40);
		return (index - 1) % 10 + 1;
	}
private:
	int rand7() {
		srand(time(0));
		return rand() % 7 + 1;
	}
};

int main() {
	Solution* solution = new Solution();
	cout << solution->rand10() << endl;
	system("pause");
	return 0;
}