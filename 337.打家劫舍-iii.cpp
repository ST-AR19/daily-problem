/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
public:`
    //记录已经计算过的结果，否则会超时
    unordered_map<TreeNode*, int> usedmap;
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        //剪枝，使用已经计算过后的答案
        if(usedmap[root]) return usedmap[root];
        //后序遍历
        //偷父节点
        int result1 = root->val;
        //由于偷了父节点，因此不考虑其左右孩子
        if(root->left) result1 += rob(root->left->left) + rob(root->left->right);
        if(root->right) result1 += rob(root->right->left) + rob(root->right->right);
        //不偷父节点
        int result2 = rob(root->left) + rob(root->right);
        usedmap[root] = max(result1, result2);
        return usedmap[root];
    }
};
// @lc code=end

