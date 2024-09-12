/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //减一是为了防止内存溢出
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i >= coins[j]) dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        if(dp[amount] == INT_MAX-1) return -1;
        return dp[amount];
    }
};
// @lc code=end

