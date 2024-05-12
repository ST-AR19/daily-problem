/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int resultstart = rob1(0, nums.size()-2, nums);
        int resultend = rob1(1, nums.size()-1, nums);
        return max(resultstart, resultend);
    }
    int rob1(int start, int end, vector<int> nums){
        vector<int> dp(end-start+2, 0);
        if(start == end) return nums[start];
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);
        for(int i = start+2; i <= end; i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[end];
    }
};
// @lc code=end

