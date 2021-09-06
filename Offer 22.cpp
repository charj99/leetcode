#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p = head;
        int length = 0;
        while(p) {
            length++;
            p = p->next;
        }
        int count = 0;
        
        p = head;
        while(p) {
            if (++count == length - k + 1) 
                break;
            p = p->next;
        }
        return p;
    }
};

void appendNode(ListNode* head, int val) {
	ListNode* p = head;
	while (p->next) {
		p = p->next;
	}
	p->next = new ListNode(val);
}

int main() {
	int k;
	cin >> k;
	int val;
	ListNode* head = NULL;
	while(cin >> val) {
		if (head == NULL) head = new ListNode(val);
		else appendNode(head, val);
	}  

	Solution* solution = new Solution();
	cout << solution->getKthFromEnd(head, k)->val << endl;
	system("pause");
	return 0;
}