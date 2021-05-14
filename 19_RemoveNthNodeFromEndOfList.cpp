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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr0 = head;
        ListNode *ptr1 = head;

        for (int i  = 0; i < n; i++) {
            ptr1 = ptr1->next;
        }

        while (ptr1 != NULL && ptr1->next != NULL) {
            ptr0 = ptr0->next;
            ptr1 = ptr1->next;
        }

        if (ptr1 == NULL) {
            head = head->next;
            delete ptr0;
        } else {
            ListNode *temp = ptr0->next;
            ptr0->next = temp->next;
            delete temp;
        }

        return head;
    }
};