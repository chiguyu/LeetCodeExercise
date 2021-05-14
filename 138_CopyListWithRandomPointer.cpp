#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *ptr = head;
        Node *dummyHead = new Node(-1);
        Node *qtr = dummyHead;
        vector<Node*> oldList;
        vector<Node*> newList;

        while (ptr != nullptr) {
            oldList.push_back(ptr);
            
            Node *newNode = new Node(-1);
            memcpy(newNode, ptr, sizeof(Node));
            qtr->next = newNode;
            newList.push_back(newNode);
            
            ptr = ptr->next;
            qtr = qtr->next;            
        }

        for(int i = 0; i < newList.size(); i++) {
            if(oldList[i]->random == nullptr) {
                newList[i]->random = nullptr;
            } else {
                vector<Node*>::iterator it = std::find(oldList.begin(), oldList.end(), oldList[i]->random);
                int index = std::distance(oldList.begin(), it);
                newList[i]->random = newList[index];
            }            
        }

        Node *res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};