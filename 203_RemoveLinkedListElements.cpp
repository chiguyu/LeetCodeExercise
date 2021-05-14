#include <iostream>

/**
 * Definition for singly-linked list.
 *  
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *res = nullptr;
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *pre = dummyHead;
        ListNode *cur = head;
        while(cur != nullptr) {
            if(cur->val == val) {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }

        res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};