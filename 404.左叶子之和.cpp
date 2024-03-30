/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int FoundLeftChildren(TreeNode* node, int sum){
        sum = 0;
        if(node->left) sum += FoundLeftChildren(node->left, sum);
        if(node->right) sum += FoundLeftChildren(node->right, sum);
        if(node->left != NULL && node->left->left == NULL && node->left->right == NULL) return sum+node->left->val;
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = 0;
        sum = FoundLeftChildren(root, sum);
        return sum;
    }
};
// @lc code=end

