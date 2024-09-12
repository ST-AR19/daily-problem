/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* traversal(vector<int> preorder, int pBegin, int pEnd, vector<int> inorder, int iBegin, int iEnd){
        if(iBegin == iEnd) return NULL;

        int rootValue = preorder[pBegin];
        TreeNode* root = new TreeNode(rootValue);

        if(pEnd - pBegin == 1) return root;

        int breakPoint;
        for(breakPoint = iBegin; breakPoint<iEnd; breakPoint++){
            if(inorder[breakPoint] == rootValue) break;
        }

        root->left = traversal(preorder, pBegin+1, pBegin+breakPoint-iBegin+1, inorder, iBegin, breakPoint);
        root->right = traversal(preorder, pBegin+breakPoint-iBegin+1, pEnd, inorder, breakPoint+1, iEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
// @lc code=end

