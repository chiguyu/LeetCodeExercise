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
    vector<int> postorderTraversal(TreeNode* root) {
        test.clear();
        postorderTraversalFunc(root);
        return test;
    }

    void postorderTraversalFunc(TreeNode* root){
        if(root != nullptr) {           
            postorderTraversalFunc(root->left);            
            postorderTraversalFunc(root->right);
            test.push_back(root->val);
        }
    }

private:
    vector<int> test;
};