/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        if(!size) return 0;
        vector<vector<int>> dp(2, vector<int>(4, 0));
        dp[0][0] -= prices[0];
        //1:持有股票的状态
        //2:度过了卖出股票的冷冻期状态
        //3:今天卖出的股票
        //4:今天为冷冻期
        for(int i = 1; i < size; i++){
            dp[i%2][0] =  max(dp[(i-1)%2][0], max(dp[(i-1)%2][3]-prices[i], dp[(i-1)%2][1]-prices[i]));
            dp[i%2][1] = max(dp[(i-1)%2][1], dp[(i-1)%2][3]);
            dp[i%2][2] = dp[(i-1)%2][0] + prices[i];
            dp[i%2][3] = dp[(i-1)%2][2];
        }
        return max(dp[(size-1)%2][1], max(dp[(size-1)%2][2], dp[(size-1)%2][3]));
    }
};
// @lc code=end

