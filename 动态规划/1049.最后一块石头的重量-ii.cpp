/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(1501, 0);
        int sum = 0;
        for(int i = 0; i < stones.size(); i++) sum+=stones[i];
        for(int i = 0; i < stones.size(); i++){
            for(int j = sum/2; j >= stones[i]; j--){
                dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
            }
        }
        return sum-dp[sum/2]-dp[sum/2];
    }
};
// @lc code=end

