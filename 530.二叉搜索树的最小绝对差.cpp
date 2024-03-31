/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int result = INT_MAX;
    TreeNode* pre = NULL;
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return result;
        int temp = getMinimumDifference(root->left);
        if(pre != NULL) result = min(result, abs(pre->val - root->val));
        pre = root;
        temp = getMinimumDifference(root->right);
        return result;
    }
};
// @lc code=end

