/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void traversal(TreeNode* node, string path, vector<string>& result){
        path += to_string(node->val);
        if(node->left == NULL && node->right == NULL) result.push_back(path);
        if(node->left) traversal(node->left, path+"->", result);
        if(node->right) traversal(node->right, path+"->", result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if(root == NULL) return result;
        traversal(root, path, result);
        return result;
    }
};
// @lc code=end

