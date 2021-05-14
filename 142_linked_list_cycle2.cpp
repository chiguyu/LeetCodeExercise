#include <iostream>
#include <set>

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *ptr = head;
        set<ListNode*> nodes;
        while(ptr != nullptr) {
            if(nodes.find(ptr->next) != nodes.end())
                return ptr->next;
            else
                nodes.insert(ptr);
            ptr = ptr->next;
        }
        return nullptr;
    }
};