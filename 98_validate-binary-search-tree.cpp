
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

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
    vector<int> data;

public:
    // 将二叉树各节点val按中序存储到data中
    void InOrder(TreeNode* root) {
        if (root != nullptr) {
            InOrder(root->left);
            data.push_back(root->val);
            InOrder(root->right);
        }
    }

    // 判断data是否严格递增并返回
    bool isValidBST(TreeNode* root) {
        InOrder(root);
        for (int i = 1; i < data.size(); i++) {
            if (data[i] <= data[i - 1]) {
                return false;
            }
        }
        return true;
    }
};