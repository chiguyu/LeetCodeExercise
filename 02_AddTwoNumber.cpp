#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int carrier = 0;
        ListNode *head = new ListNode(-1);
        ListNode *current = head;

        while (p1 || p2) {
            int sum = (p1 == nullptr ? 0 : p1->val) + (p2 == nullptr ? 0 : p2->val) + carrier;
            carrier = sum < 10 ? 0 : 1;

            ListNode *temp = new ListNode(sum < 10 ? sum : sum - 10);
            current->next = temp;
            current = current->next;

            if (p1) {
                p1 = p1->next;
            }

            if (p2) {
                p2 = p2->next;
            }
        }

        if (carrier) {
            current->next = new ListNode(carrier);
        }

        ListNode *ret = head->next;
        delete head;
        return ret;
    }
};