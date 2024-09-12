/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    void traversal(TreeNode* cur, vector<int>& vec){
        if(cur == NULL) return;
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        traversal(root, vec);
        for(int i=0; i<vec.size()-1; i++){
            if(vec[i] >= vec[i+1]) return false;
        }
        return true;
    }
    /*递归方法
    TreeNode* pre = NULL;
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        bool result = isValidBST(root->left);
        if(!pre && pre-val >= root->val) return false;
        pre = root;
        result = isValidBST(root->right);
        return result;
    }*/
};
// @lc code=end

