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
    vector<int> preorderTraversal(TreeNode* root) {
        test.clear();
        preorderTraversalFunc(root);
        return test;
    }

    void preorderTraversalFunc(TreeNode* root){
        if(root != nullptr) {
            test.push_back(root->val);
            preorderTraversalFunc(root->left);            
            preorderTraversalFunc(root->right);
        }
    }

private:
    vector<int> test;
};