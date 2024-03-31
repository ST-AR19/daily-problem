/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* traversal(vector<int> inorder, int iBegin, int iEnd, vector<int> postorder, int pBegin, int pEnd){
        if(iBegin == iEnd) return NULL;
        int rootValue = postorder[pEnd-1];
        TreeNode* root = new TreeNode(rootValue);
        if(pEnd - pBegin == 1) return root;
        int breakPoint;
        for(breakPoint = iBegin; breakPoint<iEnd; breakPoint++){
            if(inorder[breakPoint] == rootValue) break;
        }
        root->left = traversal(inorder, iBegin, breakPoint, postorder, pBegin, pBegin+breakPoint-iBegin);
        root->right = traversal(inorder, breakPoint+1, iEnd, postorder, pBegin+breakPoint-iBegin, pEnd-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, 0, inorder.size(), postorder, 0, inorder.size());
    }
};
// @lc code=end

