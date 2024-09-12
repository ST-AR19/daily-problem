/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        //贪心算法
        int result = 0;
        for(int i = 1; i < prices.size(); i++){
            if (prices[i] - prices[i-1] > 0) result += prices[i] - prices[i-1];
        }
        return result;*/
        
        //dp
        vector<vector<int>> dp(2, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++){
            dp[i%2][0] = max(dp[(i-1)%2][0], dp[(i-1)%2][1] - prices[i]);
            dp[i%2][1] = max(dp[(i-1)%2][1], dp[(i-1)%2][0] + prices[i]);
        }
        return dp[(prices.size()-1)%2][1];
    }
};
// @lc code=end

