/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                //j表示根节点的一边子树有多少个节点
                //由于还需要一个节点作为根
                //因此另外一边子树的节点个数为总节点数-j-根节点
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};
// @lc code=end

