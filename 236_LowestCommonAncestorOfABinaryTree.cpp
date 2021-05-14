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
        bool ret = false;
        if (root == nullptr) {
            return ret;
        }
        
        if (root == dest) {
            ret = true;
        } else if (FindPath(root->left, dest, path)) {
            ret = true;
        } else if (FindPath(root->right, dest, path)) {
            ret = true;
        }

        if (ret) {
            path.push_back(root);
        }

        return ret;
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
        
        std::reverse(pPath.begin(), pPath.end());
        std::reverse(qPath.begin(), qPath.end());
        int loop = min(pPath.size(), qPath.size());
        int i = 0;
        for (i = 0; i < loop && pPath[i] == qPath[i]; i++);
        return pPath[i - 1];
    }
};