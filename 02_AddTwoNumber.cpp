#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int carrier = 0;
        ListNode *res = new ListNode(-1);
        ListNode *ret = res;

        while(p1 || p2) {
            int sum = (p1 == NULL ? 0 : p1->val) + (p2 == NULL ? 0 : p2->val) + carrier;
            carrier = sum / 10;

            ListNode *temp = new ListNode(sum % 10);
            ret->next = temp;
            ret = ret->next;

            if(p1)
                p1 = p1->next;
            if(p2)
                p2 = p2->next;
        }

        if(carrier)
            ret->next = new ListNode(carrier);

        ListNode *result = res->next;
        delete res;
        return result;
    }
};