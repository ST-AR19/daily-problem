/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool judge(TreeNode* cur, int sum, int target, bool& result){
        sum += cur->val;
        if(cur->left) judge(cur->left, sum, target, result);
        if(cur->right) judge(cur->right, sum, target, result);
        if(cur->left == NULL && cur->right == NULL && sum == target) result = true;
        return result;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        int sum=0;
        bool result = false;
        judge(root, sum, targetSum, result);
        return result;
    }
    /*精简版
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right && sum == root->val) return true;
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, target-root->val);
    }*/
};
// @lc code=end

