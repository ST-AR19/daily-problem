/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        //根据初始化排除特殊情况
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 0) return 0;

        vector<int> dp(nums.size(), 0);
        vector<bool> flag(nums.size(), false);
        //初始化
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            //dp公式
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return  dp[nums.size()-1];
    }
};
// @lc code=end

