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
    //dfs递归思路
    vector<int> inorderTraversal0(TreeNode* root) {
        vector<int> res;
        inorderTraversalFunc(root, res);
        return res;
    }

    void inorderTraversalFunc(TreeNode* root, vector<int>& res){
        if (root != nullptr) {
            inorderTraversalFunc(root->left, res);
            res.push_back(root->val);
            inorderTraversalFunc(root->right, res);
        }
    }

    //使用显式栈迭代
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};