#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; 

class Solution {
public:
    /*
       Description  : CalculateLength By DFS
       Return Value : Max length of left-sub-tree & right-sub-tree
       Parameters   : 1) cur : current node  2) lengthMax reference
    */
    int CalculateLength(TreeNode* cur, int& lengthMax) {
        if (cur == nullptr) {
            return 0;
        }

        int lengthLeft = 0;
        int lengthOfLeftSubTree = CalculateLength(cur->left, lengthMax);
        if (cur->left != nullptr && cur->val == cur->left->val) {
            lengthLeft = lengthOfLeftSubTree + 1;
        }

        int lengthRight = 0;
        int lengthOfRigthtSubTree = CalculateLength(cur->right, lengthMax);
        if (cur->right != nullptr && cur->val == cur->right->val) {
            lengthRight = lengthOfRigthtSubTree + 1;
        }

        lengthMax = max(lengthMax, lengthLeft + lengthRight);
        return max(lengthLeft, lengthRight);        
    }

    int longestUnivaluePath(TreeNode* root) {
        int lengthMax = 0;
        if (root != nullptr) {
            CalculateLength(root, lengthMax);
        }
        return lengthMax;
    }
};