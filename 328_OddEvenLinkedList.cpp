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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;

        ListNode *dummyHeadOdd = new ListNode(-1);
        ListNode *tailOdd = nullptr;
        ListNode *dummyHeadEven = new ListNode(-1);

        dummyHeadOdd->next = head;
        dummyHeadEven->next = head->next;

        ListNode *ptr = head;
        int n = 1;
        while(ptr != nullptr) {
            ListNode *next = ptr->next;
            if(next != nullptr) {
                ptr->next = ptr->next->next;
            }
            if(n % 2 && ptr->next == nullptr) {
                tailOdd = ptr;
            }          
            ptr = next;
            n++;
        }

        tailOdd->next = dummyHeadEven->next;
        delete dummyHeadEven;
        delete dummyHeadOdd;
        return head;
    }
};