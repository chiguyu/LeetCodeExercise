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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr)
            return nullptr;
        
        ListNode *p = head;
        ListNode *list1 = new ListNode(-1);
        ListNode *list2 = new ListNode(-1);
        ListNode *p1 = list1;
        ListNode *p2 = list2;

        while(p) {
            /*
            ListNode *temp = new ListNode(p->val);
            if(p->val < x) {
                p1->next = temp;
                p1 = p1->next;
            } else {
                p2->next = temp;
                p2 = p2->next;
            }
            p = p->next;
            */
            
            if(p->val < x) {
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }
        p1->next = NULL;
        p2->next = NULL;

        p1->next = list2->next;
        delete list2;

        ListNode *res = list1->next;
        delete list1;

        return res;
    }
};

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(2);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(2);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    ListNode *p = node1;
    while(p) {
        cout << p->val;
        p = p->next;
    }
    cout << endl;


    Solution s;
    ListNode *ret = s.partition(node1, 3);
    p = ret;
    while(p) {
        cout << p->val;
        p = p->next;
    }
    cout << endl;

    p = node1;
    while(p) {
        delete p;
        p = p->next;
    }
/*
    p = ret;
    while(p) {
        delete p;
        p = p->next;
    }
*/
    return 0;
}