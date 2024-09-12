/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* traversal(vector<int> nums, int begin, int end){
        if(begin == end) return NULL;
        int maxAdd = 0;
        int maxValue = INT_MIN;
        for(int i=begin; i<end; i++){
            if(nums[i]> maxValue){
                maxValue = nums[i];
                maxAdd = i;
            }
        }
        TreeNode* root = new TreeNode(maxValue);
        root->left = traversal(nums, begin, maxAdd);
        root->right = traversal(nums, maxAdd+1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return traversal(nums, 0, nums.size());
    }
};
// @lc code=end

