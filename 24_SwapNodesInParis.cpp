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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *res = dummyHead;

        while(dummyHead->next && dummyHead->next->next) {
            ListNode *node1 = dummyHead->next; //node1
            ListNode *node2 = node1->next; //node2
            ListNode *node3 = node2->next; //node3

            node2->next = node1;
            node1->next = node3;
            dummyHead->next = node2;

            dummyHead = node1;
        }

        head = res->next;
        delete res;
        return head;
    }
};