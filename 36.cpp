#include <iostream>
#include <vector>
using namespace std;

#define MAXN 9
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < MAXN; i++) {
			if (!check(board[i]))
				return false;
		}

		for (int j = 0; j < MAXN; j++) {
			vector<char> column;
			for (int i = 0; i < MAXN; i++)
				column.push_back(board[i][j]);
			if (!check(column))
				return false;
		}

		for (int i = 0; i <= MAXN- 3; i += 3) 
			for (int j = 0; j <= MAXN - 3; j += 3) {
				vector<char> block;
				for (int x = i; x < i + 3; x++)
					for (int y = j; y < j + 3; y++) {
						block.push_back(board[x][y]);
					}
				if (!check(block))
					return false;
			}
		return true;
	}
private:
	bool check(vector<char>& vc) {
		vector<int> visit(MAXN, 0);
		for (int i = 0; i < vc.size(); i++)
			if (vc[i] != '.') {
				int idx = vc[i] - '0' - 1;
				if (++visit[idx] != 1)
					return false;
			}
		return true;	
	}
};

int main() {
	vector<vector<char>> board(MAXN, vector<char>(MAXN));
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			cin >> board[i][j];
	
	Solution* solution = new Solution();
	cout << (solution->isValidSudoku(board) ? "true" : "false") << endl;

	system("pause");
	return 0;
}

