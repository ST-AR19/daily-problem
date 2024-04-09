/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(key < root->val) root->left = deleteNode(root->left, key);
        if(key > root->val) root->right = deleteNode(root->right, key);
        if(key == root->val) {
            if(!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            else if(!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;;
            }
            else if(!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode* temp = root->right;
                while(temp->left){
                    temp = temp->left;
                }
                temp->left = root->left;
                root = root->right;
                return root;
            }
        }
        return root;
    }
};
// @lc code=end

