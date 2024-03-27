class Solution {
    public:
        void traversal(TreeNode* cur, vector<int>& res){
            if(cur == NULL) return;
            res.push_back(cur->val);
            traversal(cur->left, res);
            traversal(cur->right, res);
        }
        vector<int> preorderTraversal(TreeNode* root){
            vector<int> result;
            traversal(root, result);
            return result;
        }
}