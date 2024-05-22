/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        //贪心
        /*int start = -1;
        int result = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]) result = max(result, i-start);
            else start = i-1;
        }
        return result;*/
        //动态规划
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]) dp[i] = dp[i-1]+1;
            result = max(result, dp[i]);
        }
        return result;
    }
};
// @lc code=end

