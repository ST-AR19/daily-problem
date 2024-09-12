/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void Traversal(TreeNode* cur, vector<int>& res){
        if(cur == NULL) return;
        Traversal(cur->left, res);
        res.push_back(cur->val);
        Traversal(cur->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        Traversal(root, result);
        return result;
    }
};
// @lc code=end

