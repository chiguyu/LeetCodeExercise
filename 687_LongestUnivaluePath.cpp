#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
public:
    // CalculateLength By DFS
    int CalculateLength(TreeNode* cur, int& lengthMax) {
        if (cur == nullptr) {
            return 0;
        }

        int lengthLeft = 0;
        int lengthRight = 0;
        int lengthOfLeft = CalculateLength(cur->left, lengthMax);
        int lengthOfRigtht = CalculateLength(cur->right, lengthMax);

        if (cur->left != nullptr && cur->val == cur->left->val) {
            lengthLeft = lengthOfLeft + 1;
        }

        if (cur->right != nullptr && cur->val == cur->right->val) {
            lengthRight = lengthOfRigtht + 1;
        }

        lengthMax = max(lengthMax, lengthLeft + lengthRight);
        return max(lengthLeft, lengthRight);        
    }

    int longestUnivaluePath(TreeNode* root) {
        int lengthMax = 0;
        CalculateLength(root, lengthMax);
        return lengthMax;
    }
};