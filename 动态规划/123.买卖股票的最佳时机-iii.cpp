/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        //五种状态
        //0：既不购入也不卖出
        //1：第一次购入，2：第一次卖出
        //3：第二次购入，4：第二次卖出
        //由于前一个状态的改变不影响后一个状态的选择，所以不需要记录前一天的状态，于是采用一维数组
        vector<int> dp(5, 0);
        dp[1] = -prices[0];
        dp[3] = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            dp[1] = max(dp[1], dp[0]-prices[i]);
            dp[2] = max(dp[2], dp[1]+prices[i]);
            dp[3] = max(dp[3], dp[2]-prices[i]);
            dp[4] = max(dp[4], dp[3]+prices[i]);
            //cout<<dp[1]<<" "<<dp[2]<<" "<<dp[3]<<" "<<dp[4]<<endl;
        }
        return dp[4];
    }
};
// @lc code=end

