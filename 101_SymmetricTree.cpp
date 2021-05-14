#include <iostream>
#include <vector>

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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        return isSym(root->left, root->right);
    }

    bool isSym(TreeNode *left, TreeNode *right) {
        if(left == nullptr && right == nullptr) {
            return true;
        } else if (left != nullptr && right != nullptr) {
            return (left->val == right->val && isSym(left->left, right->right) && isSym(left->right, right->left));
        } else {
            return false;
        }
    }
};