#include <iostream>

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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        //create dummyHead node
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *cur = head;
        ListNode *next = cur->next;
        cur->next = NULL;
        
        // 将next节点循环插入到dummyHead和cur节点之间
        while(next) {           
            ListNode *nnext = next->next;
            next->next = cur;
            dummyHead->next = next;
            cur = next;
            next = nnext;
        }

        ListNode *res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};