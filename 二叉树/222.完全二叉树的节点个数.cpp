/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int LDepth=0, RDepth=0;
        while(left != NULL){
            left = left->left;
            LDepth++;
        }
        while(right != NULL) {
            right = right->right;
            RDepth++;
        }
        //位运算先用括号括起来，返回一个满二叉树的节点总数
        //通过判断左支与右支深度是否相同来判断是否为满二叉树
        if(LDepth == RDepth) return (2<<LDepth)-1;
        //传参不能用上面定义的left和right，需要指明
        return countNodes(root->left) + countNodes(root->right) +1;
    }
};
// @lc code=end

