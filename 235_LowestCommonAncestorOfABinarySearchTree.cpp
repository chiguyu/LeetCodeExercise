#include <iostream>
#include <vector>
#include <stack>

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
    bool FindPath(TreeNode* root, TreeNode* dest, vector<TreeNode*>& path) {
        if (root == nullptr) {
            return false;
        }
        path.push_back(root);
        if (root->val == dest->val) {
            return true;
        } else if (root->val < dest->val) {
            return FindPath(root->right, dest, path);
        } else {
            return FindPath(root->left, dest, path);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath; 
        vector<TreeNode*> qPath;
        if (!FindPath(root, p, pPath)) {
            return nullptr;
        }
        if (!FindPath(root, q, qPath)) {
            return nullptr;
        }
        if (p == q) {
            return p;
        }
        
        int loop = min(pPath.size(), qPath.size());
        int i = 0;
        for (i = 0; i < loop && pPath[i] == qPath[i]; i++);
        return pPath[i - 1];
    }
};