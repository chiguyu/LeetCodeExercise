#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for (std::vector<ListNode*>::iterator it = lists.begin() ; it != lists.end(); ++it) {
            for (ListNode *p = *it; p != NULL; p = p->next) {
                pq.push(p->val);
            }
        }

        ListNode *head = new ListNode(-1);
        ListNode *p = head;
        while(!pq.empty()) {
            ListNode *temp = new ListNode(pq.top());
            pq.pop();
            p->next = temp;
            p = p->next;
        }

        ListNode *res = head->next;
        delete head;
        return res;
    }
};