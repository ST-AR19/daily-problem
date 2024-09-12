/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool compare(TreeNode* left, TreeNode* right){
        if(left == NULL && right != NULL) return false;
        if(left != NULL && right == NULL) return false;
        if(left == NULL && right == NULL) return true;
        if(left->val != right->val) return false;
        
        bool out = compare(left->left, right->left);
        bool in = compare(left->right, right->right);
        return out && in;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        return compare(p,q);
    }
};
// @lc code=end

