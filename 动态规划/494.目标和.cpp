/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(abs(target) > sum) return 0;
        if((sum + target) % 2 == 1) return 0;
        sum = (target + sum) / 2;
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = sum; j >= nums[i]; j--){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};
// @lc code=end

