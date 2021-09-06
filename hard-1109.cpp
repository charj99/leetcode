#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
class Node {
private:
public:
	Node* lson;
	Node* rson;
	int value;
	int l;
	int r;
	Node(Node* _lson, Node* _rson, int _l, int _r) {
		lson = _lson;
		rson = _rson;
		l = _l; 
		r = _r;
		value = 0;
	}

	Node(int _l, int _r) {
		lson = rson = NULL;
		l = _l;
		r = _r;
		value = 0;
	}

	void add(int _value) {
		value += _value;
	}

	void pushDown() {
		lson->value += value;
		rson->value += value;
		value = 0;
	}
};

class Tree {
public:
	Node* root;
	Tree(int n) {
		root = buildNodes(1, n);
	}
	void add(int l, int r, int value) {
		addNodes(root, l, r, value);
	}
	int query(int index) {
		return queryNode(root, index);
	}
	void print() {
		printNodes(root);
#ifdef DEBUG
		cout << endl;
#endif
	}
	void myDelete() {
		deleteNodes(&root);
	}
private:
	Node* buildNodes(int l, int r);
	void addNodes(Node* node, int l, int r, int value);
	int queryNode(Node* node, int index);
	void printNodes(Node* node);
	void deleteNodes(Node** node_p);
};

Node* Tree::buildNodes(int l, int r) {
	if (l == r) return new Node(l, r);
	int mid = (l + r) / 2;
	Node* lson = buildNodes(l, mid);
	Node* rson = buildNodes(mid + 1, r);
	return new Node(lson, rson, l, r);
}

void Tree::addNodes(Node*node, int l, int r, int value) {
	if (node->l >= l && node->r <= r) {
		node->add(value);
		return;
	}	
	int mid = (node->l + node->r) / 2;
	if (l <= mid) addNodes(node->lson, l, r, value);
	if (r >= mid + 1) addNodes(node->rson, l, r, value);
}

int Tree::queryNode(Node* node, int index) {
	if (node->l == node->r) {
		return node->value;
	}
	int mid = (node->l + node->r) / 2;
	node->pushDown();
	if (index <= mid) return queryNode(node->lson, index);
	else return queryNode(node->rson, index);
}

void Tree::printNodes(Node* node) {
	if (node == NULL) return;
	cout << "[" << node->l << ", " << node->r << "]: " << node->value << " ";
	if (node->l == node->r) return;
	int mid = (node->l + node->r) / 2;
	printNodes(node->lson);
	printNodes(node->rson);
}

void Tree::deleteNodes(Node** node_p) {
	Node* node = *node_p;
	if (node->l == node->r) {
		delete node;
		*node_p = NULL;
		return;
	}
	int mid = (node->l + node->r) / 2;
	deleteNodes(&node->lson);
	deleteNodes(&node->rson);
	delete node;
	*node_p = NULL;
}

class Solution {
public:
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
		Tree* tree = new Tree(n);
		for (auto booking: bookings) {
			int first = booking[0];
			int last = booking[1];
			int seats = booking[2];
			tree->add(first, last, seats);
#ifdef DEBUG
			tree->print();
#endif
		}
		vector<int> answer;
		for (int i = 0; i < n; i++)
			answer.push_back(tree->query(i + 1));
		tree->myDelete();
#ifdef DEBUG
		tree->print();
#endif 
		return answer;
	}
};

int main() {
	int n;
	cin >> n;
	int from, last, seats;
	vector<vector<int>> bookings;
	while (cin >> from >> last >> seats) {
		vector<int> booking(3);
		booking[0] = from;
		booking[1] = last;
		booking[2] = seats;

		bookings.push_back(booking);
	}
	
	Solution* solution = new Solution();
	vector<int> answer =  solution->corpFlightBookings(bookings, n);
	for (int i = 0; i < n; i++)
		cout << answer[i] << " ";
	system("pause");
	return 0;
}