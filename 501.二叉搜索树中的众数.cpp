/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int count, MaxCount;
    TreeNode* pre;
    vector<int> result;
    void traversal(TreeNode* cur){
        if(cur == NULL) return;

        traversal(cur->left);

        if(pre == NULL) count = 1;
        else if(cur->val == pre->val) count++;
        else count = 1;

        pre = cur;
        if(count == MaxCount) result.push_back(cur->val);
        else if(count > MaxCount) {
            MaxCount = count;
            result.clear();
            result.push_back(cur->val);
        }
        
        traversal(cur->right);
        
        return;
    }
    vector<int> findMode(TreeNode* root) {
        count = 0;
        MaxCount = 0;
        pre = NULL;
        result.clear();
        traversal(root);
        return result;
    }
};
// @lc code=end

