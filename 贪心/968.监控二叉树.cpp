/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int result=0;
    //0表示没有被覆盖，1表示有摄像头，2表示被摄像头覆盖
    int traversal(TreeNode* root){
        //需要让叶子节点的父节点有摄像头才合适
        //所以需要让空节点返回2，这样叶子节点的返回值就是0
        //则叶子节点的父节点的返回值就成了1，有摄像头的状态了
        if(root == NULL) return 2;
        int left = traversal(root->left);
        int right = traversal(root->right);
        if(left == 2 && right == 2) return 0;
        else if(left == 0 || right == 0) {
            //要先加再返回，否则加不上
            result++;
            return 1;
        }else return 2;
    }
    int minCameraCover(TreeNode* root) {
        //额外再判断一下根节点
        if(traversal(root) == 0) result++;
        return result;
    }
};
// @lc code=end

