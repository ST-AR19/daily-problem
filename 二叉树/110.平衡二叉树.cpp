/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int GetHeight(TreeNode* node){
        if(node == NULL) return 0;

        int LH = GetHeight(node->left);
        if(LH == -1) return -1;
        int RH = GetHeight(node->right);
        if(RH == -1) return -1;
        return abs(LH - RH) > 1 ? -1 : 1+max(LH, RH);
    }
    bool isBalanced(TreeNode* root) {
        return GetHeight(root) == -1 ? false : true;
    }
};
// @lc code=end

