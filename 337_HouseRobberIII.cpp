#include <unordered_map>

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
private:
    unordered_map<TreeNode *,  int>mp;
public:
    int rob(TreeNode* root) {
        if (root == nullptr)
            return 0;

        if (mp.count(root))
            return mp.at(root);
        
        int res = 0;
        int amountNoRob = rob(root->left) + rob(root->right);
        int amountRob = root->val + 
                        (root->left != nullptr ?  rob(root->left->left) + rob(root->left->right) : 0) +
                        (root->right != nullptr ? rob(root->right->left) + rob(root->right->right) : 0);
        res = std::max(amountRob, amountNoRob);
        mp.insert(std::make_pair(root, res));
        return res;
    }
};