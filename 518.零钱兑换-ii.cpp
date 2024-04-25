/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        //先遍历物品后遍历容量能得到组合数，反之得到的是排列数
        for(int i = 0; i < coins.size(); i++){
            //完全背包从当前遍历元素的值为起点遍历
            for(int j = coins[i]; j <= amount; j++){
                dp[j] += dp[j - coins[i]];
                //cout<<dp[j]<<" ";
            }
            //cout<<endl;
        }
        return dp[amount];
    }
};
// @lc code=end

