/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
/*
    //贪心
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int result = 0;
        for(int i = 0; i<prices.size(); i++){
            low = min(low, prices[i]);
            result = max(result, prices[i] - low);
        }
        return result;
    }
*/
    //dp
    int maxProfit(vector<int>& prices) {
        //定义一个2*2的数组来表示当天和前一天的状态
        vector<vector<int>> dp(2, vector<int>(2));
        //表示第一天持有股票的时候产生的收益
        dp[0][0] -= prices[0];
        //表示第一天没有持有股票的时候产生的收益
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++){
            dp[i%2][1] = max(dp[(i-1)%2][1], dp[(i-1)%2][0] + prices[i]);
            dp[i%2][0] = max(dp[(i-1)%2][0], -prices[i]);
        }
        return dp[(prices.size()-1)%2][1];
    }
};
// @lc code=end

