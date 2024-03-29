/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        vector<int> result; 
        while(!que.empty()){
            int MaxValue = INT_MIN;
            int size = que.size();
            int temp;
            for(int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                MaxValue = node->val > MaxValue ? node->val : MaxValue;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(MaxValue);
        }
        return result;
    }
};
// @lc code=end

