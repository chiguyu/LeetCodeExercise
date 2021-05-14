#include <iostream>
#include <vector>
#include <queue>
#include <utility>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*,int>> qTreeNode;

        if(root != nullptr)
            qTreeNode.push(std::make_pair(root, 0));

        while(!qTreeNode.empty()) {
            // Handle front of qTreeNode
            TreeNode *ptr = qTreeNode.front().first;
            int level = qTreeNode.front().second;
            qTreeNode.pop();

            // Handle level of TreeNode
            if(level < res.size()) {
                if(level % 2) {
                    res[level].insert(res[level].begin(), ptr->val);
                } else {
                    res[level].push_back(ptr->val);
                }                    
            } else {
                res.push_back(vector<int> {ptr->val});
            }
            level++;

            // push queue if needed
            if(ptr->left != nullptr)
                qTreeNode.push(std::make_pair(ptr->left, level));
            if(ptr->right != nullptr)
                qTreeNode.push(std::make_pair(ptr->right, level));
        }

        return res; 
    }
};