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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)
            return head;
        
        //遍历得到第m-1个节点以及第m个节点
        //create dummyHead node
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *ptr = dummyHead;
        for(int i = 0; i < m - 1; i++){
            ptr = ptr->next;
        }      
        ListNode *prem = ptr;
        ListNode *curm = ptr->next;

        //遍历依次将第m+1至第n个节点插到第m-1个节点之后
        ListNode *cur = curm;
        ListNode *next = cur->next;
        ListNode *nnext = nullptr;
        for(int i = m + 1; i <= n && next; i++){           
            nnext = next->next;
            next->next = cur;
            prem->next = next;
            cur = next;
            next = nnext;
        }
        curm->next = nnext;

        ListNode *res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};