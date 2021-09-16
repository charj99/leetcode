#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
// #define DEBUG
#define MAXT 26
typedef struct Trie {
	bool mark;
	struct Trie* nodes[MAXT];
	Trie() {
		mark = false;
		for (int i = 0; i < MAXT; i++)
			nodes[i] = NULL;
	}
} Trie;

Trie* buildTree(vector<string>& words);
void destroyTree(Trie* p);
void printTree(Trie* p, string word);
int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		Trie* root = buildTree(words);
		int n = board.size();
		int m = board[0].size();
#ifdef DEBUG
		printTree(root, "");
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cout << i << ", " << j << ": " << board[i][j] << endl;
			}
#endif
		set<string> result;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char ch = board[i][j];
				int idx = ch - 'a';
				if (root->nodes[idx] != NULL) {
					board[i][j] = '#';
					// can not convert char directly to string
					string word = "a";
					word[0] = ch;
					dfs(i, j, root->nodes[idx], result, board, word);
					board[i][j] = ch;
				}	
			}
		}
		destroyTree(root);
		vector<string> rtn;
		set<string>::iterator iter;
		for (iter = result.begin(); iter != result.end(); iter++)
			rtn.push_back(*iter);
		return rtn;
	}
private:
	void dfs(int x, int y, Trie* p, set<string>& result, vector<vector<char>>& board, string word) {
		if (p->mark) 
			result.insert(word);
		
		int n = board.size();
		int m = board[0].size();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				char ch = board[nx][ny];
				int idx = ch - 'a';
				if (ch != '#' && p->nodes[idx] != NULL) {
					board[nx][ny] = '#';
					dfs(nx, ny, p->nodes[idx], result, board, word + ch);
					board[nx][ny] = ch;
				}
			}
		}
	}
};

void printTree(Trie* p, string word) {
	if (p->mark) cout << word << endl;
	for (int i = 0; i < MAXT; i++)
		if (p->nodes[i] != NULL) {
			char ch = i + 'a';
			printTree(p->nodes[i], word + ch);
		}
}

void destroyTree(Trie* p) {
	if (p == NULL) return;
	for (int i = 0; i < MAXT; i++)
		destroyTree(p->nodes[i]);
	delete p;	
}
void insertTree(Trie* root, const string& word) {
	Trie* p = root;
	for (int i = 0; i < word.size(); i++) {
		int idx = word[i] - 'a';
		if (p->nodes[idx] == NULL) {
			p->nodes[idx] = new Trie();
		}
		p = p->nodes[idx];
	}
	p->mark = true;
}

Trie* buildTree(vector<string>& words) {
	Trie* root = new Trie();
	for (int i = 0; i < words.size(); i++) {
		insertTree(root, words[i]);
	}
	return root;
}

int main () {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board;
	vector<char> line;
	char ch;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ch;
			line.push_back(ch);
		}
		board.push_back(line);
		line.clear();
	}

	int k;
	cin >> k;
	string word;
	vector<string> words;
	for (int i = 0; i < k; i++) {
		cin >> word;
		words.push_back(word);
	}
	Solution* solution = new Solution();
	vector<string> result = solution->findWords(board, words);
	cout << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	system("pause");
	return 0;
}