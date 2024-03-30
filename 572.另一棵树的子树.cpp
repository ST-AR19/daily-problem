/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
        if(left != NULL && right == NULL) return false;
        if(left == NULL && right != NULL) return false;
        if(left == NULL && right == NULL) return true;
        if(left->val != right->val)return false;
        bool LC=compare(left->left, right->left);
        bool RC=compare(left->right, right->right);
        return LC && RC;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true;
        if(root == NULL && subRoot != NULL) return false;
        queue<TreeNode*> que;
        que.push(root);
        bool result = false;
        while(!que.empty()){
            int size = que.size();
            for(int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->val == subRoot->val) result = compare(node, subRoot);
                if(result) return result;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return result;
    }
};
// @lc code=end

