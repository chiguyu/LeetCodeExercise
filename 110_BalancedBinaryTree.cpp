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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        balanceState = true;
        getDepth(root);

        return balanceState;
    }

    int getDepth(TreeNode *node) {
        if(node == nullptr || !balanceState)
            return 0;
        
        int leftDep = getDepth(node->left);
        int rightDep = getDepth(node->right);

        if(std::abs(leftDep - rightDep) > 1)
            balanceState = false;
        
        return leftDep >= rightDep ? leftDep + 1 : rightDep + 1;
    }
private:
    bool balanceState;
};